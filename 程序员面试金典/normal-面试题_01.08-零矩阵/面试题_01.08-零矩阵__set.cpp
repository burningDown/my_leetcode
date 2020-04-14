class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> cols;
        unordered_set<int> rows;

        const int h = matrix.size();
        const int w = matrix[0].size();

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(matrix[i][j] == 0)
                {
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }

        for(unordered_set<int>::iterator it=cols.begin();it!=cols.end();it++)
        {
            for(int i=0;i<h;i++)
                matrix[i][*it] = 0;
        }
        for(unordered_set<int>::iterator it=rows.begin();it!=rows.end();it++)
        {
            for(int i=0;i<w;i++)
                matrix[*it][i] = 0;
        }
    }
};