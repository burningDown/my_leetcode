class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int h = matrix.size();
        const int w = matrix[0].size();

        bool colZero = false, rowZero = false;
        for(int i=0;i<w;i++)
        {
            if(matrix[0][i] == 0)
            {
                rowZero = true;
                break;
            }
        }
        for(int i=0;i<h;i++)
        {
            if(matrix[i][0] == 0)
            {
                colZero = true;
                break;
            }
        }

        for(int i=1;i<h;i++)
        {
            for(int j=1;j<w;j++)
            {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for(int j=1;j<w;j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i=1;i<h;i++)
                    matrix[i][j] = 0;
            }
        }
        for(int i=1;i<h;i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j=1;j<w;j++)
                    matrix[i][j] = 0;
            }
        }

        if(rowZero)
        {
            for(int i=0;i<w;i++)
                matrix[0][i] = 0;
        }
        if(colZero)
        {
            for(int i=0;i<h;i++)
                matrix[i][0] = 0;
        }
    }
};