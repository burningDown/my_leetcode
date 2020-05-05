class StreamRank {
private:
    int C[50010];
public:
    StreamRank() {
        memset(C, 0, 50010 * sizeof(int));
    }
    
    void track(int x) {
        ++x;
        while(x <= 50001) ++C[x], x += (x & (-x));
    }
    
    int getRankOfNumber(int x) {
        int sum = 0;
        ++x;
        while(x > 0) sum += C[x], x &= x - 1;
        return sum;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */