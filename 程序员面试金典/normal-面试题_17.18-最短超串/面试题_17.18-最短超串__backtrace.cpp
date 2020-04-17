vector<int> backtrace(vector<int> &big, unordered_map<int, int> &smallMap, vector<vector<vector<int>>> &dp, int i, int j)
{
    while(smallMap.count(big[i]) == 0)
        i++;
    while(smallMap.count(big[j]) == 0)
        j--;

    if(dp[i][j][0] >= 0)
        return dp[i][j];

    vector<int> minRegion = {i, j}, temp;
    
    if(smallMap[big[i]] > 1)
    {
        smallMap[big[i]]--;
        temp = backtrace(big, smallMap, dp, i+1, j);
        if(temp[1] - temp[0] < minRegion[1] - minRegion[0] || temp[1] - temp[0] == minRegion[1] - minRegion[0] && temp[0] < minRegion[0])
            minRegion = temp;
        smallMap[big[i]]++;
    }

    if(smallMap[big[j]] > 1)
    {
        smallMap[big[j]]--;
        temp = backtrace(big, smallMap, dp, i, j-1);
        if(temp[1] - temp[0] < minRegion[1] - minRegion[0] || temp[1] - temp[0] == minRegion[1] - minRegion[0] && temp[0] < minRegion[0])
            minRegion = temp;
        smallMap[big[j]]++;
    }
    dp[i][j] = minRegion;
    return minRegion;
}

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map<int, int> smallMap;
        vector<vector<vector<int>>> dp(big.size(), vector<vector<int>>(big.size(), {-1, -1}));

        for(int i : small)
            smallMap[i] = 0;
        
        for(int i : big)
        {
            if(smallMap.count(i) > 0)
            {
                smallMap[i]++;
            }
        }

        for(auto it=smallMap.begin();it!=smallMap.end();it++)
        {
            if(it->second == 0)
                return {};
        }

        return backtrace(big, smallMap, dp, 0, big.size()-1);
    }
};