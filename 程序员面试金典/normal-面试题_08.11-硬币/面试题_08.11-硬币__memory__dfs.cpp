class Solution {
private:
    int helper(vector<vector<int>> &dp, int n, int value)
    {
        int count = 0;
        if(n <= 0)
            return 1;
        
        if(dp[n][value] > 0)
            return dp[n][value];
        
        if(n >= 25 && value >= 3)
            count = (count + helper(dp, n-25, 3)) % 1000000007;
        if(n >= 10 && value >= 2)
            count = (count + helper(dp, n-10, 2)) % 1000000007;
        if(n >= 5 && value >= 1)
            count = (count + helper(dp, n-5, 1)) % 1000000007;
        if(n >= 1 && value >= 0)
            count = (count + helper(dp, n-1, 0)) % 1000000007;
        dp[n][value] = count;
        return count;
    }
public:
    int waysToChange(int n) {
        vector<vector<int>> dp(n+5, vector<int>(4, 0));
        return helper(dp, n, 3);
    }
};