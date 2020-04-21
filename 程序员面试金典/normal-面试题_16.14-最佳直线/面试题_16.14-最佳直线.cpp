inline double getK(double x1, double y1, double x2, double y2)
{
    return x1 == x2 ? INT_MAX : (y1 - y2) / (x1 - x2);
}

inline double getB(double x1, double y1, double x2, double y2)
{
    return x1 == x2 ? x1 : (x1 * y2 - x2 * y1) / (x1 - x2);
}

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        unordered_map<double, unordered_map<double, unordered_set<int>>> linesMap;
        double maxk, maxb, k, b;
        int maxPoints = 0, minIdx;
        const int l = points.size();
        vector<int> result;
        
        for(int i=0;i<l;i++)
        {
            for(int j=i+1;j<l;j++)
            {
                k = getK(points[i][0], points[i][1], points[j][0], points[j][1]);
                b = getB(points[i][0], points[i][1], points[j][0], points[j][1]);
                linesMap[k][b].insert(i);
                linesMap[k][b].insert(j);

                if(linesMap[k][b].size() > maxPoints)
                {
                    maxPoints = linesMap[k][b].size();
                    maxk = k;
                    maxb = b;
                }
            }
        }

        result.reserve(4);
        for(int i=0;i<2;i++)
        {
            minIdx = INT_MAX;
            for(auto it=linesMap[maxk][maxb].begin();it!=linesMap[maxk][maxb].end();++it)
            {
                if(*it < minIdx)
                    minIdx = *it;
            }
            result.push_back(minIdx);
            linesMap[maxk][maxb].erase(minIdx);
        }

        return result;
    }
};