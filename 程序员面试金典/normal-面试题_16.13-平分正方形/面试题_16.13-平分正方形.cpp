class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        vector<double> center1 = {square1[0] + square1[2] / 2.0, square1[1] + square1[2] / 2.0};
        vector<double> center2 = {square2[0] + square2[2] / 2.0, square2[1] + square2[2] / 2.0};

        if(center1[0] == center2[0])
        {
            double maxY = (double)max(square1[1] + square1[2], square2[1] + square2[2]);
            double minY = (double)min(square1[1], square2[1]);

            return { center1[0], minY, center2[0], maxY };
        }
        else
        {
            double k = (center1[1] - center2[1]) / (center1[0] - center2[0]);
            double b = (center1[0] * center2[1] - center2[0] * center1[1]) / (center1[0] - center2[0]);
            if(fabs(k) >= 1.0)
            {
                double maxY = (double)max(square1[1] + square1[2], square2[1] + square2[2]);
                double minY = (double)min(square1[1], square2[1]);

                if(k >= 0)
                    return { (minY - b) / k, minY, (maxY - b) / k, maxY };
                else
                    return { (maxY - b) / k, maxY, (minY - b) / k, minY };
            }
            else
            {
                double maxX = (double)max(square1[0] + square1[2], square2[0] + square2[2]);
                double minX = (double)min(square1[0], square2[0]);

                return { minX, k * minX + b, maxX, k * maxX + b };
            }
        }
    }
};