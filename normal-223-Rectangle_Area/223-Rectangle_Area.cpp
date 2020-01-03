class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const long long &maxx1 = E > A ? E : A;
        const long long &minx2 = C < G ? C : G;
        const long long &maxy1 = B > F ? B : F;
        const long long &miny2 = H < D ? H : D;

        const long long &hmin = miny2 - maxy1;
        const long long &wmin = minx2 - maxx1;

        return (long long)((C-A))*(D-B) + (long long)((H-F))*(G-E) - (long long)(hmin>0?hmin:0) * (long long)(wmin>0?wmin:0);
    }
};