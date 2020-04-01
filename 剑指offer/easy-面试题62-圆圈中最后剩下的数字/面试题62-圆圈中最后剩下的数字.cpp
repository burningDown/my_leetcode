class Solution {
public:
    int lastRemaining(int n, int m) {
        // if(n == 2)
        //     return m % n;
        // else
        //     return (m + lastRemaining(n-1, m)) % n;
        int res = 0;
        for(int i=2;i<=n;i++)
            res = (m + res) % i;
        return res;
    }
};