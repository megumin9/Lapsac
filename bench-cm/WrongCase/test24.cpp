// https://github.com/mapnik/mapnik/commit/4a192c319baeb20052d6ddfae27b9c6bd2492b3e

// Violation of Anti-Symmetry 

bool compare_24(const rgba& x, const rgba& y) 
{
    int t1 = (int)x.a + x.r + x.g + x.b;
    int t2 = (int)y.a + y.r + y.g + y.b;
    if (t1 != t2) return t1 < t2;

    return (((int)x.a - y.a) >> 24) +
        (((int)x.r - y.r) >> 16) +
        (((int)x.g - y.g) >> 8) +
        (((int)x.b - y.b));
}