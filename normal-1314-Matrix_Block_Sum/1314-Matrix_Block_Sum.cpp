class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int m = mat.size();
        const int n = mat[0].size();
        int i0, i1, j0, j1;
        vector<vector<int>> integratedMap(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                integratedMap[i + 1][j + 1] = mat[i][j] + integratedMap[i][j + 1] + integratedMap[i + 1][j] - integratedMap[i][j];
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                i0 = max(0, i - K);
                i1 = min(m - 1, i + K);
                j0 = max(0, j - K);
                j1 = min(n - 1, j + K);

                res[i][j] =integratedMap[i1 + 1][j1 + 1] - integratedMap[i0][j1 + 1] - integratedMap[i1 + 1][j0] + integratedMap[i0][j0];
            }
        }

        return res;
    }
};