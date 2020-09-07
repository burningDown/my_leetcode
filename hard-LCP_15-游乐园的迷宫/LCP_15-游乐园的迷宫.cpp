const char dirDict[] = "LR";

class Solution {
private:
    bool trackback(vector<vector<int>> &points, vector<int> &path, string &direction, vector<bool> &mask, int idx, pair<int, int> dir, pair<int, int> lastP)
    {
        const int l = points.size();

        if(path.size() == l)
            return true;
        
        for(int i=0;i<l;i++)
        {
            if(!mask[i])
            {
                pair<int, int> tDir = {points[i][0] - lastP.first, points[i][1] - lastP.second};
                if(dirDict[dir.first * tDir.second - dir.second * tDir.first < 0] == direction[idx])
                {
                    mask[i] = true;
                    path.push_back(i);
                    if(trackback(points, path, direction, mask, idx+1, tDir, {points[i][0], points[i][1]}))
                        return true;
                    path.pop_back();
                    mask[i] = false;
                }
            }
        }
        return false;
    }
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {
        const int l = points.size();
        vector<int> path;
        vector<bool> mask(l, false);

        for(int i=0;i<l;i++)
        {
            mask[i] = true;
            path.push_back(i);
            for(int j=0;j<l;j++)
            {
                if(!mask[j])
                {
                    mask[j] = true;
                    path.push_back(j);
                    pair<int, int> tDir = {points[j][0] - points[i][0], points[j][1] - points[i][1]};
                    if(trackback(points, path, direction, mask, 0, tDir, {points[j][0], points[j][1]}))
                        return path;

                    path.pop_back();
                    mask[j] = false;
                }
            }
            path.pop_back();
            mask[i] = false;
        }

        return {};
    }
};