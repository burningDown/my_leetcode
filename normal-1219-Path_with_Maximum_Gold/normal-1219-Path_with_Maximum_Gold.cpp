class Solution {
private:
    bool visited[15*15+10];
    int lx;
    int ly;
    int max;
    void dfs(int i, int j, int count, vector<vector<int>> &grid)
    {
    	int temp=0;
        visited[i*lx+j] = true;
        if(count > max)
            max = count;

        if(i>0 && !visited[(i-1)*lx+j] && grid[i-1][j] > 0)
            dfs(i-1, j, count+grid[i-1][j], grid);
        if(j>0 && !visited[i*lx+j-1] && grid[i][j-1] > 0)
            dfs(i, j-1, count+grid[i][j-1], grid);
        if(i<ly-1 && !visited[(i+1)*lx+j] && grid[i+1][j] > 0)
            dfs(i+1, j, count+grid[i+1][j], grid);
        if(j<lx-1 && !visited[i*lx+j+1] && grid[i][j+1] > 0)
            dfs(i, j+1, count+grid[i][j+1], grid);

        visited[i*lx+j] = false;
    }
public:
    Solution():max(0), visited({0}){}
    int getMaximumGold(vector<vector<int>>& grid) {
        int count;
        ly = grid.size();
        lx = grid[0].size();

        for(int i=0;i<ly;i++)
        {
            for(int j=0;j<lx;j++)
            {
            	if(grid[i][j] != 0)
                    dfs(i, j, grid[i][j], grid);
            }
        }


        return max;
    }
};