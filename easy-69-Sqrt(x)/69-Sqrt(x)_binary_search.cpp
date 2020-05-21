class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        if(46340 * 46340 <= x)
            return 46340;
        
        int i = 1, j = min(x, 46340);
        int mid, s;

        while(i < j)
        {
            mid = (i + j) / 2;
            s = mid * mid;

            if(s == x)
                return mid;
            else if(s < x)
                i = mid + 1;
            else
                j = mid;
        }

        return i-1;
    }
};