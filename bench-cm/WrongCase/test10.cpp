//https://github.com/xbmc/xbmc/commit/238c86786f993acabfaae8681254b907560f1122

// Violation of Anti-Symmetry 

bool compare_10(RESOLUTION_WHR i, RESOLUTION_WHR j) {
    return (i.width < j.width
            || (i.width == j.width && i.height < j.height)
            || (i.width == j.width && i.height == j.height && i.flags != j.flags));
}