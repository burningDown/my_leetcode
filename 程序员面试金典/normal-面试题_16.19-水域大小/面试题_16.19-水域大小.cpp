class Solution {
private:
    int dfs(vector<vector<int>>& land, int i, int j)
    {
        if(i<0 || i>=land.size() || j<0 || j>= land[0].size() || land[i][j] != 0)
            return 0;
        
        int count = 1;

        land[i][j] = -1;
        count += dfs(land, i-1, j);
        count += dfs(land, i+1, j);
        count += dfs(land, i, j-1);
        count += dfs(land, i, j+1);
        
        count += dfs(land, i+1, j-1);
        count += dfs(land, i+1, j+1);
        count += dfs(land, i-1, j-1);
        count += dfs(land, i-1, j+1);
        return count;
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        const int h = land.size();
        const int w = land[0].size();
        vector<int> result;

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(land[i][j] == 0)
                    result.push_back(dfs(land, i, j));
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};