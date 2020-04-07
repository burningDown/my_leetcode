class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int l = matrix.size();
        int i, j;
        for(int layer = 0;layer < l/2;layer++)
        {
            for(i = layer;i<l-layer-1;i++)
            {
                matrix[i][l-layer-1] += matrix[layer][i];
                matrix[layer][i] = matrix[i][l-layer-1] - matrix[layer][i];
                matrix[i][l-layer-1] -= matrix[layer][i];
                
                matrix[l-layer-1][l-i-1] += matrix[layer][i];
                matrix[layer][i] = matrix[l-layer-1][l-i-1] - matrix[layer][i];
                matrix[l-layer-1][l-i-1] -= matrix[layer][i];
                
                matrix[l-i-1][layer] += matrix[layer][i];
                matrix[layer][i] = matrix[l-i-1][layer] - matrix[layer][i];
                matrix[l-i-1][layer] -= matrix[layer][i];
            }
        }
    }
};