class Solution {
private:
    int dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return 0;
        
        grid[i][j] = 'q';

        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);

        return 1;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        const int h = grid.size();

        if(h <= 0)
            return 0;
        
        const int w = grid[0].size();

        if(w <= 0)
            return 0;

        int count = 0;

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                count += dfs(grid, i, j);
            }
        }
        return count;
    }
};