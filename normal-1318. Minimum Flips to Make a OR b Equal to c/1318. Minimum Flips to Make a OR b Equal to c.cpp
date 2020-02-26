class Solution {
public:
    int minFlips(int a, int b, int c) {
        int max;
        max = a>b ? a:b;
        max = c>max ? c:max;

        const int &n = int(log2(max));
        int count = 0;
        for(int i=0;i<=n;i++, a=a>>1, b=b>>1, c=c>>1)
        {
            if((c&1) == 1)
            {
                if((a&1) == 0 && (b&1) == 0)
                {
                    count++;
                }
            }
            else
            {
                if((a&1) == 1)
                    count++;
                if((b&1) == 1)
                    count++;
            }
        }
        return count;
    }
};