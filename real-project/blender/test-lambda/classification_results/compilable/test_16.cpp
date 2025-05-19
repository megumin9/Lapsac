#include <bits/stdc++.h>
#include <string>

struct ThumbnailCache {
    struct Request {
        std::string file_path;
        int stream_index;
        int frame_index;
    };
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ThumbnailCache::Request &a, const ThumbnailCache::Request &b) {
    if (a.file_path != b.file_path) {
        return a.file_path < b.file_path;
    }
    if (a.stream_index != b.stream_index) {
        return a.stream_index < b.stream_index;
    }
    return a.frame_index < b.frame_index;
}

void test1(ThumbnailCache::Request a, ThumbnailCache::Request b, ThumbnailCache::Request c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(ThumbnailCache::Request a, ThumbnailCache::Request b, ThumbnailCache::Request c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(ThumbnailCache::Request a, ThumbnailCache::Request b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(ThumbnailCache::Request a, ThumbnailCache::Request b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(ThumbnailCache::Request a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}