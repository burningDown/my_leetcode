class Solution {
private:
    vector<int> backtrack(string &s, int start, vector<vector<int>> &dp)
    {
        const int l = s.size();
        if(start >= l)
            return {};
        
        if(dp[start].size() > 0)
            return dp[start];

        vector<int> sub = backtrack(s, start + 1, dp);
        vector<int> res;
        res.push_back(start);
        if(start + 1 < l && s[start + 1] == s[start])
            res.push_back(start + 1);
        for(int i=0;i<sub.size();i++)
        {
            if(sub[i] + 1 < l && s[sub[i]+1] == s[start])
            {
                res.push_back(sub[i]+1);
            }
        }
        dp[start] = res;
        return res;
    }
public:
    int countSubstrings(string s) {
        const int l = s.size();
        int count = 0;
        vector<vector<int>> dp(l);
        for(int i=0;i<l;i++)
            count += backtrack(s, i, dp).size();
        return count;
    }
};