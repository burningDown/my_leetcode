class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        const int h = matrix.size();
        const int w = matrix[0].size();
        int p1 = h - 1, p2 = 0;

        while(p1 >= 0 && p2 < w)
        {
            if(matrix[p1][p2] == target)
                return true;
            else if(matrix[p1][p2] < target)
                p2++;
            else
                p1--;
        }
        return false;
    }
};