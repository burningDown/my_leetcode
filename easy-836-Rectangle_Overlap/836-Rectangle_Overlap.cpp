class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        const int &x1 = rec1[0] > rec2[0] ? rec1[0] : rec2[0];
        const int &x2 = rec1[2] < rec2[2] ? rec1[2] : rec2[2];
        const int &y1 = rec1[1] > rec2[1] ? rec1[1] : rec2[1];
        const int &y2 = rec1[3] < rec2[3] ? rec1[3] : rec2[3];

        if(x2 > x1 && y2 > y1)
            return true;
        else
            return false;
    }
};