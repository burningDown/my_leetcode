class Solution {
    bool binaryFind(vector<vector<int>> &matrix, int target, int y)
    {
        int mid;
        int i = 0, j = matrix[0].size() - 1;
        while(i < j)
        {
            mid = (i + j) / 2;
            if(matrix[y][mid] < target)
                i = mid + 1;
            else if(matrix[y][mid] > target)
                j = mid;
            else
                return true;
        }
        return matrix[y][i] == target;
    }
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        const int h = matrix.size();
        const int w = matrix[0].size();

        for(int i=0;i<h;i++)
        {
            if(matrix[i][0] <= target && matrix[i][w-1] >= target)
            {
                if(binaryFind(matrix, target, i))
                    return true;
            }
        }
        return false;
    }
};