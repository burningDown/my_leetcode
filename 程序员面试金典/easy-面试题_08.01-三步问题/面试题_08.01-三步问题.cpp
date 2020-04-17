class Solution {
public:
    int waysToStep(int n) {
        int n1 = 0, n2 = 0, n3 = 1, total = 0;
        for(int i=1;i<=n;i++)
        {
            total = ((n1 + n2) % 1000000007 + n3) % 1000000007;
            n1 = n2;
            n2 = n3;
            n3 = total;
        }
        return total;
    }
};