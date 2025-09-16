class PPERequester_DMSPsyTrip extends PPERequesterBase
{
    // Materials / layers
    protected const int MAT_COLOR   = PostProcessEffectType.Glow;
    protected const int LAYER_COLOR = 9001;
    protected const int MAT_RBLUR   = PostProcessEffectType.RadialBlur;
    protected const int MAT_CHROMA  = PostProcessEffectType.ChromAber;

    // Built-in timing
    protected const int COLOR_DELAY_MS = 1000; // wait ~1s before color starts
    protected const int COLOR_RAMP_MS  = 400;  // ease color in over 0.4s
    protected const int RELEASE_MS     = 5000; // smooth 5s release before final fade

    // State
    protected int   m_StepMs;
    protected int   m_FadeMs;
    protected float m_ColorIntensity;   // overlay factor (0..1, lower = more transparent)
    protected bool  m_Running;

    protected int   m_TotalMs;          
    protected int   m_ElapsedMs;        
    protected float m_T;                

    protected bool  m_InRelease;
    protected int   m_ReleaseElapsed;

    /**
     * Start a smooth trip:
     *  - totalMs:      main visible duration (e.g. 60000 ≈ 60s)
     *  - stepMs:       update interval (50ms = very smooth)
     *  - colorIntensity: overlay factor (0.18–0.22 is subtle)
     *  - blurStrength:   radial blur max amplitude
     *  - chromaStrength: chromatic aberration amplitude (~0.003–0.004 subtle)
     *  - fadeMs:         final fade after the release section
     */
    void StartTrip(int totalMs = 60000, int stepMs = 50, float colorIntensity = 0.20, float blurStrength = 0.34, float chromaStrength = 0.0035, int fadeMs = 1200)
    {
        m_TotalMs        = totalMs;
        m_StepMs         = stepMs;
        m_FadeMs         = fadeMs;
        m_ColorIntensity = colorIntensity;

        m_ElapsedMs      = 0;
        m_T              = 0.0;
        m_Running        = true;
        m_InRelease      = false;
        m_ReleaseElapsed = 0;

        Start();
        Tick(blurStrength, chromaStrength);
    }

    protected void Tick(float blurStrength, float chromaStrength)
    {
        if (!m_Running) return;

        if (!m_InRelease)
        {
            // ===== Main section (0..m_TotalMs)
            m_T = Math.Clamp(m_ElapsedMs / Math.Max(1.0, m_TotalMs), 0.0, 1.0);

            // --- COLOR (HSV rainbow), delayed & ramped
            float cycles = 2.0; // two hue spins across the main duration
            float hRaw   = m_T * cycles;
            float H      = hRaw - Math.Floor(hRaw); // wrap 0..1 without '%'
            float S      = 0.85;
            float V      = 1.00;

            float gate = 0.0;
            if (m_ElapsedMs > COLOR_DELAY_MS)
            {
                float gateT = Math.Clamp((m_ElapsedMs - COLOR_DELAY_MS) / Math.Max(1.0, COLOR_RAMP_MS), 0.0, 1.0);
                gate = Easing.EaseInOutSine(gateT);
            }

            array<float> col = HSVtoRGB(H, S, V);
            float colorFactor = m_ColorIntensity * gate;
            SetTargetValueColor(MAT_COLOR, PPEGlow.PARAM_OVERLAYCOLOR, col, LAYER_COLOR, PPOperators.SET);
            SetTargetValueFloat(MAT_COLOR, PPEGlow.PARAM_OVERLAYFACTOR, false, colorFactor, LAYER_COLOR, PPOperators.HIGHEST);

            // --- BLUR + CHROMA (start immediately; bell 0→1→0 across main)
            float env = 0.5 - 0.5 * Math.Cos(m_T * Math.PI * 2.0 * 0.5);

            float blur = blurStrength * env;
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_POWERX,  false, blur, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_POWERY,  false, blur, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_OFFSETX, false, 0.0,  PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_OFFSETY, false, 0.0,  PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_PIXELSCALE, false, 0.5, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);

            float theta = m_T * Math.PI2;
            float caX = Math.AbsFloat(Math.Sin(theta * 0.75)) * chromaStrength;
            float caY = Math.AbsFloat(Math.Cos(theta * 0.50)) * chromaStrength;
            SetTargetValueFloat(MAT_CHROMA, PPEChromAber.PARAM_POWERX, false, caX, PPEChromAber.L_0_INTRO, PPOperators.SET);
            SetTargetValueFloat(MAT_CHROMA, PPEChromAber.PARAM_POWERY, false, caY, PPEChromAber.L_0_INTRO, PPOperators.SET);

            // Advance time
            m_ElapsedMs += m_StepMs;

            if (m_ElapsedMs >= m_TotalMs)
            {
                m_InRelease      = true;
                m_ReleaseElapsed = 0;
            }
        }
        else
        {
            // ===== Release section (smoothly fade EVERYTHING over RELEASE_MS)
            float rT  = Math.Clamp(m_ReleaseElapsed / Math.Max(1.0, RELEASE_MS), 0.0, 1.0);
            float rel = 1.0 - Easing.EaseInOutSine(rT); // 1 -> 0

            // Fade overlay factor
            SetTargetValueFloat(MAT_COLOR, PPEGlow.PARAM_OVERLAYFACTOR, false, m_ColorIntensity * rel, LAYER_COLOR, PPOperators.HIGHEST);

            // Fade blur & chroma
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_POWERX,  false, 0.34 * rel, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
            SetTargetValueFloat(MAT_RBLUR, PPERadialBlur.PARAM_POWERY,  false, 0.34 * rel, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);

            float caMax = 0.0035 * rel;
            SetTargetValueFloat(MAT_CHROMA, PPEChromAber.PARAM_POWERX, false, caMax, PPEChromAber.L_0_INTRO, PPOperators.SET);
            SetTargetValueFloat(MAT_CHROMA, PPEChromAber.PARAM_POWERY, false, caMax, PPEChromAber.L_0_INTRO, PPOperators.SET);

            m_ReleaseElapsed += m_StepMs;

            if (m_ReleaseElapsed >= RELEASE_MS)
            {
                m_Running = false;
                ResetToDefault(m_FadeMs);
                return;
            }
        }

        // Schedule next tick
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(Tick, m_StepMs, false, blurStrength, chromaStrength);
    }

    override void Stop(Param par = null)
    {
        super.Stop(par);
        ResetToDefaultsImmediate();
    }

    protected void ResetToDefault(int fadeMs)
    {
        // Fade to defaults
        SetTargetValueFloatDefault(MAT_COLOR, PPEGlow.PARAM_OVERLAYFACTOR);
        SetTargetValueColorDefault(MAT_COLOR, PPEGlow.PARAM_OVERLAYCOLOR);

        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_POWERX);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_POWERY);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_OFFSETX);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_OFFSETY);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_PIXELSCALE);

        SetTargetValueFloatDefault(MAT_CHROMA, PPEChromAber.PARAM_POWERX);
        SetTargetValueFloatDefault(MAT_CHROMA, PPEChromAber.PARAM_POWERY);

        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(Stop, fadeMs, false, null);
    }

    protected void ResetToDefaultsImmediate()
    {
        SetTargetValueFloatDefault(MAT_COLOR, PPEGlow.PARAM_OVERLAYFACTOR);
        SetTargetValueColorDefault(MAT_COLOR, PPEGlow.PARAM_OVERLAYCOLOR);

        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_POWERX);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_POWERY);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_OFFSETX);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_OFFSETY);
        SetTargetValueFloatDefault(MAT_RBLUR, PPERadialBlur.PARAM_PIXELSCALE);

        SetTargetValueFloatDefault(MAT_CHROMA, PPEChromAber.PARAM_POWERX);
        SetTargetValueFloatDefault(MAT_CHROMA, PPEChromAber.PARAM_POWERY);
    }

    // ===== HSV utilities (no float %)
    protected array<float> HSVtoRGB(float h, float s, float v)
    {
        float k = h * 6.0;
        int   i = Math.Floor(k);
        float f = k - Math.Floor(k);

        float p = v * (1.0 - s);
        float q = v * (1.0 - f * s);
        float t = v * (1.0 - (1.0 - f) * s);

        int ii = i % 6;
        float r, g, b;
        if (ii == 0) { r = v; g = t; b = p; }
        else if (ii == 1) { r = q; g = v; b = p; }
        else if (ii == 2) { r = p; g = v; b = t; }
        else if (ii == 3) { r = p; g = q; b = v; }
        else if (ii == 4) { r = t; g = p; b = v; }
        else              { r = v; g = p; b = q; }

        array<float> rgb = new array<float>();
        rgb.Insert(r); rgb.Insert(g); rgb.Insert(b); rgb.Insert(1.0);
        return rgb;
    }
}
