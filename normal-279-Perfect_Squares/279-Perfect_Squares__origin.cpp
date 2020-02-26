class Solution {
public:
    int numSquares(int n) {
        int mini = 9999999;
        int r;
        const int s = int(sqrt(n));
        if(s*s == n)
            return 1;
        else
        {
            for(int i=s;i>0;i--)
            {
                if((r = numSquares(n-i*i)) < mini)
                    mini = r;
            }
        }
        return mini + 1;
    }
};