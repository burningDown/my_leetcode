inline int argmin(const int dp[], const int p[], const int idxDict[])
{
    int &&minIdx = dp[p[0]] * idxDict[0] < dp[p[1]] * idxDict[1] ? 0 : 1;
    return dp[p[minIdx]] * idxDict[minIdx] < dp[p[2]] * idxDict[2] ? minIdx : 2;
}
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[2000] = { 0 };
        int d = 0;
        int p[3] = { 0 };
        const int idxDict[3] = {2, 3, 5};
        int i = 1;
        int minIdx;

        dp[d++] = 1;
        while(i < n)
        {
            minIdx = argmin(dp, p, idxDict);
            if(dp[p[minIdx]] * idxDict[minIdx] != dp[d-1])
            {
                dp[d++] = dp[p[minIdx]] * idxDict[minIdx];
                p[minIdx]++;
                i++;
            }
            else
                p[minIdx]++;
        }
        return dp[d-1];
    }
};