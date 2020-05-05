inline long min(long a, long b)
{
    return a < b ? a : b;
}

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        long minSub;
        int p1 = 0, p2 = 0;
        const int la = a.size();
        const int lb = b.size();

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        minSub = abs(long(b[0]) - long(a[0]));

        while(p1 < la && p2 < lb)
        {
            minSub = min(minSub, abs(long(b[p2]) - long(a[p1])));
            if(a[p1] <= b[p2])
                ++p1;
            else
                ++p2;
        }

        return int(minSub);
    }
};