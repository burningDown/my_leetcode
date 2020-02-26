bool compare(vector<int> &p1, vector<int> &p2)
{
    return p1[0] < p2[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int &l = points.size();
        int i = 0, j = 0, minY, arrows = 0;
        sort(points.begin(), points.end(), compare);
        while(i<l)
        {
            j = i;
            minY = points[i][1];
            while(j<l && points[j][0] < points[i][1])
            {
                if(points[j][1] < minY)
                    minY = points[j][1];
                ++j;
            }
            j = i;
            while(j<l && points[j][0] <= minY)
                ++j;
            ++arrows;
            i = j;
        }
        return arrows;
    }
};