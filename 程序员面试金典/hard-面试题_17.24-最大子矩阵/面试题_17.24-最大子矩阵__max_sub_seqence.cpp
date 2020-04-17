inline int getSum(int integralMap[220][220], int i1, int j1, int i2, int j2)
{
    return integralMap[i2][j2] - integralMap[i1-1][j2] - integralMap[i2][j1-1] + integralMap[i1-1][j1-1];
}
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int integralMap[220][220] = { 0 };
        const int h = matrix.size();
        const int w = matrix[0].size();

        int mp1[2] = { 1, 1 }, mp2[2] = { 1, 1 };
        int maxSum = matrix[0][0];

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                integralMap[i +1][j +1] = matrix[i][j] + integralMap[i-1 +1][j +1] + integralMap[i +1][j-1 +1] - integralMap[i-1 +1][j-1 +1];
            }
        }

        for(int start=1;start<=w;start++)
        {
            for(int cur=start;cur<=w;cur++)
            {
                int i=1, j=1, sum;
                for(;j<=h;j++)
                {
                    sum = getSum(integralMap, i, start, j, cur);
                    if(sum > maxSum)
                    {
                        mp1[0] = i;
                        mp1[1] = start;
                        mp2[0] = j;
                        mp2[1] = cur;
                        maxSum = sum;
                    }
                    if(sum < 0)
                    {
                        i = j + 1;
                    }
                }
            }
        }
        return {mp1[0]-1, mp1[1]-1, mp2[0]-1, mp2[1]-1};
    }
};