const double EPS = 1e-6;

class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        const double y1max = end1[1] > start1[1] ? end1[1] : start1[1];
        const double y1min = end1[1] < start1[1] ? end1[1] : start1[1];
        const double y2max = end2[1] > start2[1] ? end2[1] : start2[1];
        const double y2min = end2[1] < start2[1] ? end2[1] : start2[1];

        const double x1max = end1[0] > start1[0] ? end1[0] : start1[0];
        const double x1min = end1[0] < start1[0] ? end1[0] : start1[0];
        const double x2max = end2[0] > start2[0] ? end2[0] : start2[0];
        const double x2min = end2[0] < start2[0] ? end2[0] : start2[0];

        double x0, y0;

        if(start1[0] == end1[0] || start2[0] == end2[0])
        {
            if(start1[0] == end1[0] && start2[0] == end2[0])
            {
                if(start1[0] == start2[0])
                {
                    x0 = x1min;
                    y0 = y1min;

                    if(y0 - EPS <= y2max && y0 >= y2min - EPS && y0 - EPS <= y1max && y0 >= y1min - EPS && x0 - EPS <= x2max && x0 >= x2min - EPS && x0 - EPS <= x1max && x0 >= x1min - EPS)
                        return {x0, y0};
                    x0 = x2min;
                    y0 = y2min;
                    if(y0 - EPS <= y2max && y0 >= y2min - EPS && y0 - EPS <= y1max && y0 >= y1min - EPS && x0 - EPS <= x2max && x0 >= x2min - EPS && x0 - EPS <= x1max && x0 >= x1min - EPS)
                        return {x0, y0};
                }
            }
            else
            {
                if(start1[0] == end1[0])
                {
                    const double k2 = double(end2[1] - start2[1]) / double(end2[0] - start2[0]);
                    const double b2 = start2[1] - k2 * start2[0];

                    x0 = start1[0];
                    y0 = k2 * x0 + b2;
                }
                else
                {
                    const double k1 = double(end1[1] - start1[1]) / double(end1[0] - start1[0]);
                    const double b1 = start1[1] - k1 * start1[0];

                    x0 = start2[0];
                    y0 = k1 * x0 + b1;
                }
                if(y0 - EPS <= y2max && y0 >= y2min - EPS && y0 - EPS <= y1max && y0 >= y1min - EPS && x0 - EPS <= x2max && x0 >= x2min - EPS && x0 - EPS <= x1max && x0 >= x1min - EPS)
                    return {x0, y0};
            }
        }

        const double k1 = double(end1[1] - start1[1]) / double(end1[0] - start1[0]);
        const double k2 = double(end2[1] - start2[1]) / double(end2[0] - start2[0]);
        const double b1 = start1[1] - k1 * start1[0];
        const double b2 = start2[1] - k2 * start2[0];
        
        if(k1 != k2)
        {
            x0 = (b2 - b1) / (k1 - k2);
            y0 = (k1*b2 - k2*b1) / (k1 - k2);

            if(y0 - EPS <= y2max && y0 >= y2min - EPS && y0 - EPS <= y1max && y0 >= y1min - EPS && x0 - EPS <= x2max && x0 >= x2min - EPS && x0 - EPS <= x1max && x0 >= x1min - EPS)
                return {x0, y0};
        }
        else
        {
            if(b1 == b2)
            {
                if(start1[0] < end1[0])
                {
                    x0 = start1[0];
                    y0 = start1[1];
                }
                else
                {
                    x0 = end1[0];
                    y0 = end1[1];
                }
                if(y0 - EPS <= y2max && y0 >= y2min - EPS && y0 - EPS <= y1max && y0 >= y1min - EPS && x0 - EPS <= x2max && x0 >= x2min - EPS && x0 - EPS <= x1max && x0 >= x1min - EPS)
                    return {x0, y0};
                
                
                if(start2[0] < end2[0])
                {
                    x0 = start2[0];
                    y0 = start2[1];
                }
                else
                {
                    x0 = end2[0];
                    y0 = end2[1];
                }
                if(y0 - EPS <= y2max && y0 >= y2min - EPS && y0 - EPS <= y1max && y0 >= y1min - EPS && x0 - EPS <= x2max && x0 >= x2min - EPS && x0 - EPS <= x1max && x0 >= x1min - EPS)
                    return {x0, y0};
            }
        }
        return {};
    }
};