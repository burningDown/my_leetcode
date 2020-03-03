class Solution {
private:
    vector<vector<bool>> visited;
    int count;
    int li, lj;
    void dfs(vector<vector<int>> &A, int i, int j)
    {
        if(A[i][j] == 0 || visited[i][j])
            return;
        visited[i][j] = true;
        count--;

        if(i>0)
            dfs(A, i-1, j);
        if(i<li-1)
            dfs(A, i+1, j);
        if(j>0)
            dfs(A, i, j-1);
        if(j<lj-1)
            dfs(A, i, j+1);
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        li = A.size();
        lj = A[0].size();
        count = 0;
        visited.resize(li, vector<bool>(lj, false));

        for(int i=0;i<li;i++)
        {
            for(int j=0;j<lj;j++)
                count += A[i][j];
        }

        for(int i=0;i<li;i++)
        {
            dfs(A, i, 0);
            dfs(A, i, lj-1);
        }
        for(int j=0;j<lj;j++)
        {
            dfs(A, 0, j);
            dfs(A, li-1, j);
        }

        return count;
    }
};