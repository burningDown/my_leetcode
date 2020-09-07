class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> strMap;
        int res = 0;

        string col;
        for(auto &m : matrix)
        {
            col.clear();
            if(m[0] == 0)
            {
                for(auto i : m)
                    col.push_back(i + '0');
            }
            else
            {
                for(auto i : m)
                    col.push_back(!i + '0');
            }
            strMap[col]++;
            res = max(res, strMap[col]);
        }
        return res;
    }
};