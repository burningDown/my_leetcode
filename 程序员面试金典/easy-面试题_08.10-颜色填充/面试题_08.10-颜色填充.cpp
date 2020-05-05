class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        stack<vector<int>> stateStack;
        vector<int> p;
        int oldColor;
        const int h = image.size();
        const int w = image[0].size();

        oldColor = image[sr][sc];
        if(oldColor == newColor)
            return image;
        
        stateStack.push({sr, sc});
        while(!stateStack.empty())
        {
            p = stateStack.top();
            stateStack.pop();

            if(image[p[0]][p[1]] != newColor)
            {
                image[p[0]][p[1]] = newColor;
                if(p[0] > 0 && image[p[0]-1][p[1]] == oldColor)
                    stateStack.push({p[0]-1, p[1]});
                if(p[0] < h-1 && image[p[0]+1][p[1]] == oldColor)
                    stateStack.push({p[0]+1, p[1]});
                if(p[1] > 0 && image[p[0]][p[1]-1] == oldColor)
                    stateStack.push({p[0], p[1]-1});
                if(p[1] < w-1 && image[p[0]][p[1]+1] == oldColor)
                    stateStack.push({p[0], p[1]+1});
            }
        }
        return image;
    }
};