class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int l = days.size();
        int dp[400] = { 0 };
        int nextDay;

        for(int i=l-1;i>=0;i--)
        {
            dp[i] = costs[0] + dp[i + 1];

            for(nextDay=i+1;nextDay<l && days[nextDay]-days[i] < 7;nextDay++) ;

            dp[i] = min(dp[i], costs[1] + dp[nextDay]);

            for(nextDay=i+1;nextDay<l && days[nextDay]-days[i] < 30;nextDay++) ;

            dp[i] = min(dp[i], costs[2] + dp[nextDay]);
        }

        return dp[0];
    }
};
