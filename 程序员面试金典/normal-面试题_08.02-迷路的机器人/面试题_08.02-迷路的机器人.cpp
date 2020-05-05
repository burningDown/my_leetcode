class Solution {
private:
    bool trackback(vector<vector<int>> &obstacleGrid, vector<vector<int>> &path, int i, int j)
    {
        if(i < 0 || i >= obstacleGrid.size() || j < 0 || j >= obstacleGrid[0].size() || obstacleGrid[i][j] != 0)
            return false;
        
        obstacleGrid[i][j] = 100;
        path.push_back({i, j});
        
        if(i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
            return true;

        if(trackback(obstacleGrid, path, i + 1, j))
            return true;
        if(trackback(obstacleGrid, path, i, j + 1))
            return true;
        path.pop_back();

        return false;
    }
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return {};
        
        vector<vector<int>> path;

        path.reserve(obstacleGrid.size() * obstacleGrid[0].size());

        trackback(obstacleGrid, path, 0, 0);
        return path;
    }
};