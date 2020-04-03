class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        const int h = matrix.size();
        if(h == 0)
            return result;
        const int w = matrix[0].size();
        if(w == 0)
            return result;
        result.reserve(h * w + 10);

        const int maxLayer = (w > h ? h - 1 : w - 1) / 2;
        for(int layer = 0;layer <= maxLayer;layer++)
        {
            if(layer >= w-layer)
                break;
            for(int i=layer;i<w-layer;i++)
                result.push_back(matrix[layer][i]);
            if(layer+1 >= h-layer)
                break;
            for(int i=layer+1;i<h-layer;i++)
                result.push_back(matrix[i][w - layer - 1]);
            if(layer+1 >= w-layer)
                break;
            for(int i=layer+1;i<w-layer;i++)
                result.push_back(matrix[h - layer - 1][w - i - 1]);
            if(layer+1 >= h-layer-1)
                break;
            for(int i=layer+1;i<h-layer-1;i++)
                result.push_back(matrix[h - i - 1][layer]);
        }
        return result;
    }
};