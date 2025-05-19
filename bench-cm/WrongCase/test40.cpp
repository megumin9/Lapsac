//https://github.com/seaweedfs/seaweedfs/commit/008ac38ebcc4b3e370b299cf14fe894d5361bb04  

// Violation of Anti-Reflexivity

int compare_40(Point a, Point b) {

    if (a.x != b.x) {
        return a.x - b.x;
    }


    if (a.ts != b.ts) {
        return a.ts - b.ts;
    }

    if (!a.isStart) {
        return -1; 
    }
    return 1;  
}