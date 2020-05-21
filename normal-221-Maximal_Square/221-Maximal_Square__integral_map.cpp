class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int h = matrix.size();
        if(h == 0)
            return 0;
        const int w = matrix[0].size();
        if(w == 0)
            return 0;

        int maxw = 0;

        vector<vector<int>> intergralMap(h + 2, vector<int>(w + 2, 0));

        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                intergralMap[i+1][j+1] = matrix[i][j] - '0' + intergralMap[i][j+1] + intergralMap[i+1][j] - intergralMap[i][j];

        for(int i=0;i<h-maxw;i++)
        {
            for(int j=0;j<w-maxw;j++)
            {
                while(i+maxw<h && j+maxw<w && intergralMap[i+maxw+1][j+maxw+1] - intergralMap[i][j+maxw+1] - intergralMap[i+maxw+1][j] + intergralMap[i][j] == (maxw + 1) * (maxw + 1))
                    maxw++;
            }
        }
        return maxw * maxw;
    }
};