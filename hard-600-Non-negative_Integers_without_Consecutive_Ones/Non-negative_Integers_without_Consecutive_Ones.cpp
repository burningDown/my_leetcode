class Solution {
public:
    int findIntegers(int num) {
        int n = int(log2(num)) + 1;
        int shi = 1 << n-1;
        int weights[35] = {-1}, w = 0;
        bool flag = true;
        for(int i=n;i>=0;i--, shi=shi>>1)
        {
            if(num&shi)
            {
                weights[++w] = i;
                if(weights[w-1] == weights[w]+1)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
            weights[++w] = 1;
        int l2=1, l1=1, result=0, i=1, temp;
        for(;w>0;w--)
        {
            for(;i<weights[w];i++)
            {
                temp = l2;
                l2 += l1;
                l1 = temp;
            }
            result += l2;
        }
        return result;
    }
};