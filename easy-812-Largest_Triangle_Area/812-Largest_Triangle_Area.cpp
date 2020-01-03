class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int l = points.size();
        int p1, p2, p3;
        double s, smax=0;
        for(int i=0;i<l;i++)
        {
            int &a = points[i][0];
            int &b = points[i][1];
            for(int j=i+1;j<l;j++)
            {
                int &c = points[j][0];
                int &d = points[j][1];
                for(int k=j+1;k<l;k++)
                {
                    int &e = points[k][0];
                    int &f = points[k][1];
                    s = abs(0.5 * (c*f+b*e+a*d-a*f-b*c-d*e));
                    if(s > smax)
                        smax = s;
                }
            }
        }
        return smax;
    }
};