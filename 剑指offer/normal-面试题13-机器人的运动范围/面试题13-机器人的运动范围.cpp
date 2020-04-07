inline int digitSum(int x)
{
    return x%10 + x/10%10 + x/100%10;
}
class Solution {
private:
    int dfs(vector<vector<bool>> &visited, const int &m, const int &n, const int &k, int i, int j)
    {
        if(i<0 || i>=m || j <0 || j>=n || visited[i][j] || digitSum(i) + digitSum(j) > k)
            return 0;
            
        visited[i][j] = true;

        return 1 + dfs(visited, m, n, k, i+1, j) + dfs(visited, m, n, k, i-1, j) + dfs(visited, m, n, k, i, j+1) + dfs(visited, m, n, k, i, j-1);
    }
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(visited, m, n, k, 0, 0);
    }
};