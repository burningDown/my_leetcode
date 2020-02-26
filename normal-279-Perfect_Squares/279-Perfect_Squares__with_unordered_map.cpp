unordered_map<int, int> stepMap;
class Solution {
public:
    int numSquares(int n) {
        int mini = 9999999;
        int r;
        const int s = int(sqrt(n));
        if(s*s == n)
            return 1;
        
        unordered_map<int, int>::const_iterator got = stepMap.find(n);
        if(got != stepMap.end())
            return got->second;
        else
        {
            for(int i=s;i>0;i--)
            {
                const int r = numSquares(n-i*i);
                stepMap[n-i*i] = r;
                if(r < mini)
                    mini = r;
            }
        }
        return mini + 1;
    }
};