bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
}
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        const int l = points.size();
        int i, j, iy, jy, side1, side2, area = INT_MAX;

        sort(points.begin(), points.end(), cmp);
        i = j = iy = jy = 0;
        while(i<l)
        {
            for(j=i;j<l;j++)
            {
                if(points[j][0] > points[i][0])
                    break;
            }
            while(j<l)
            {
                iy = i;
                jy = j;
                side1 = -1;
                side2 = -1;
                while(iy<l&&points[iy][0]==points[i][0]&&jy<l&&points[jy][0]==points[j][0])
                {
                    while(iy<l&&points[iy][0]==points[i][0]&&jy<l&&points[jy][0]==points[j][0])
                    {
                        if(points[iy][1] < points[jy][1])
                            ++iy;
                        else if(points[iy][1] == points[jy][1])
                        {
                            side1 = side2;
                            side2 = points[iy][1];
                            if(side1 != -1 && (side2 - side1)*(points[j][0] - points[i][0]) < area)
                                area = (side2 - side1)*(points[j][0] - points[i][0]);
                            ++iy;
                        }
                        else
                            break;
                    }
                    while(iy<l&&points[iy][0]==points[i][0]&&jy<l&&points[jy][0]==points[j][0])
                    {
                        if(points[iy][1] > points[jy][1])
                            ++jy;
                        else if(points[iy][1] == points[jy][1])
                        {
                            side1 = side2;
                            side2 = points[jy][1];
                            if(side1 != -1 && (side2 - side1)*(points[j][0] - points[i][0]) < area)
                                area = (side2 - side1)*(points[j][0] - points[i][0]);
                            ++jy;
                        }
                        else
                            break;
                    }
                }
                for(j++;j<l;j++)
                {
                    if(points[j][0] > points[j-1][0])
                        break;
                }
            }
            for(i++;i<l;i++)
            {
                if(points[i][0] > points[i-1][0])
                    break;
            }
        }
        return area < INT_MAX ? area : 0;
    }
};