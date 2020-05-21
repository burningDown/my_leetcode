class Solution {
    int backtrack(vector<int> &days, int d, vector<int> &dp, vector<int> &costs)
    {
        const int l = days.size();
        if(d >= l)
            return 0;
        
        if(dp[d] > 0)
            return dp[d];
        
        int res = costs[0] + backtrack(days, d + 1, dp, costs);
        int nextDay;

        for(nextDay=d+1;nextDay<l && days[nextDay]-days[d] < 7;nextDay++) ;

        res = min(res, costs[1] + backtrack(days, nextDay, dp, costs));

        for(nextDay=d+1;nextDay<l && days[nextDay]-days[d] < 30;nextDay++) ;

        res = min(res, costs[2] + backtrack(days, nextDay, dp, costs));

        dp[d] = res;
        return res;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), 0);
        return backtrack(days, 0, dp, costs);
    }
};