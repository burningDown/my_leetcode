class Solution {
private:
    int dfs(vector<int> &piles, int dp[][2 * 100 + 5], int start, int M, int total, int l)
    {
        if(dp[start][M] > 0)
            return dp[start][M];

        if(2 * M >= l - start)
            return total;

        int res = 0;
        int sum = 0;
         
        for(int X=1;X<=2*M;X++)
        {
            sum += piles[start+X-1];
            res = max(res, total - dfs(piles, dp, start+X, max(M, X), total - sum, l));
        } 

        dp[start][M] = res;
        return res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int total = 0;
        int dp[100 + 10][2 * 100 + 5] = { 0 };
        for(int i : piles)
            total += i;
        return dfs(piles, dp, 0, 1, total, piles.size());
    }
};