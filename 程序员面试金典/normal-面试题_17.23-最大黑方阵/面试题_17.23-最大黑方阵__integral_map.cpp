inline int getSum(int integralMap[220][220], int i1, int j1, int i2, int j2)
{
    return integralMap[i2 +1][j2 +1] - integralMap[i1][j2 +1] - integralMap[i2 +1][j1] + integralMap[i1][j1];
}
class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int integralMap[220][220] = { 0 };
        const int h = matrix.size();
        const int w = matrix[0].size();
        int r=0, c=0, size=0, tempSize;

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                integralMap[i +1][j +1] = matrix[i][j] + integralMap[i][j +1] + integralMap[i +1][j] - integralMap[i][j];
            }
        }

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                tempSize = size;
                while(i + tempSize < h && j + tempSize < w)
                {
                    if(tempSize <= 1)
                    {
                        if(getSum(integralMap, i, j, i + tempSize, j + tempSize) == 0)
                        {
                            r = i;
                            c = j;
                            tempSize++;
                            size = tempSize;
                        }
                        else
                        {
                            tempSize++;
                        }
                    }
                    else
                    {
                        if(getSum(integralMap, i, j, i + tempSize, j + tempSize) - getSum(integralMap, i+1, j+1, i+tempSize-1, j+tempSize-1) == 0)
                        {
                            r = i;
                            c = j;
                            tempSize++;
                            size = tempSize;
                        }
                        else
                        {
                            tempSize++;
                        }
                    }
                }
            }
        }

        if(size > 0)
            return {r, c, size};
        else
            return {};
    }
};