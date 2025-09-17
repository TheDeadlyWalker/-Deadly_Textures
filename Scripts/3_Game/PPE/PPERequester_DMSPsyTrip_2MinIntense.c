class PPERequester_DMSPsyTrip_2MinIntense extends PPERequester_DMSPsyTrip
{
    void StartTrip2MinIntense(float colorIntensity = 0.38, float blurStrength = 0.55, float chromaStrength = 0.0065, int fadeMs = 1500)
    {
        StartTrip(120000, 50, colorIntensity, blurStrength, chromaStrength, fadeMs);
    }
}