//https://github.com/musescore/MuseScore/commit/bfbdfef8f5a0e0b69951219e3d112e6652b6561c

// Violation of Anti-Symmetry 

bool compare_15(const InstrumentTemplate* templ1, const InstrumentTemplate* templ2) {
    int minMaxPitch; 
    const int diff1 = findMaxPitchDiff(minMaxPitch, templ1);
    const int diff2 = findMaxPitchDiff(minMaxPitch, templ2);

    if (diff1 != diff2) {
        return diff1 < diff2;
    }

    if (templ1->drumset && !templ2->drumset) {
        return true;
    }

    return templ1->genres.size() > templ2->genres.size();
}