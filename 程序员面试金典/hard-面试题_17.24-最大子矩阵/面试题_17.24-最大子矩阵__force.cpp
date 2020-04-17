class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int integralMap[220][220] = { 0 };
        const int h = matrix.size();
        const int w = matrix[0].size();

        int p1[2] = { 1, 1 }, p2[2] = { 1, 1 };
        int mp1[2] = { 1, 1 }, mp2[2] = { 1, 1 };
        int maxSum = matrix[0][0];

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                integralMap[i +1][j +1] = matrix[i][j] + integralMap[i-1 +1][j +1] + integralMap[i +1][j-1 +1] - integralMap[i-1 +1][j-1 +1];
            }
        }

        for(p1[0]=1;p1[0]<=h;p1[0]++)
        {
            for(p1[1]=1;p1[1]<=w;p1[1]++)
            {
                for(p2[0]=p1[0];p2[0]<=h;p2[0]++)
                {
                    for(p2[1]=p1[1];p2[1]<=w;p2[1]++)
                    {
                        if(integralMap[p2[0]][p2[1]] - integralMap[p1[0]-1][p2[1]] - integralMap[p2[0]][p1[1]-1] + integralMap[p1[0]-1][p1[1]-1] > maxSum)
                        {
                            maxSum = integralMap[p2[0]][p2[1]] - integralMap[p1[0]-1][p2[1]] - integralMap[p2[0]][p1[1]-1] + integralMap[p1[0]-1][p1[1]-1];
                            mp1[0] = p1[0];
                            mp1[1] = p1[1];
                            mp2[0] = p2[0];
                            mp2[1] = p2[1];
                        }
                    }
                }
            }
        }
        return {mp1[0]-1, mp1[1]-1, mp2[0]-1, mp2[1]-1};
    }
};