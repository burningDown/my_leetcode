inline int min(int a, int b)
{
    return a < b ? a : b;
}
inline int max(int a, int b)
{
    return a > b ? a : b;
}

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1)
            return 0;

        int p1 = 0, p2 = height.size()-1;
        int max1 = height[p1], max2 = height[p2];
        int count = 0;

        while(p1 < p2)
        {
            if(height[p1] <= height[p2])
            {
                max1 = max(max1, height[p1]);
                count += max1 - height[p1];
                p1++;
            }
            else
            {
                max2 = max(max2, height[p2]);
                count += max2 - height[p2];
                p2--;
            }
        }
        return count;
    }
};