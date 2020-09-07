class Solution {
private:
    int backtrack(int n, int idx, vector<int> &manager, vector<int> &informTime, vector<int> &dp)
    {
        if(idx == -1)
            return 0;
        
        if(dp[idx] < 0)
            dp[idx] = backtrack(n, manager[idx], manager, informTime, dp);

        return informTime[idx] + dp[idx];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> dp(n, -1);
        int maxTime = 0;

        for(int i=0;i<n;i++)
            maxTime = max(maxTime, backtrack(n, i, manager, informTime, dp));
        
        return maxTime;
    }
};