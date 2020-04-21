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
    int maxArea(vector<int>& height) {
        const int l = height.size();
        int p1 = 0, p2 = l-1;
        int maxVolume = 0;
        while(p1 < p2)
        {
            maxVolume = max((p2 - p1) * min(height[p1], height[p2]), maxVolume);
            if(height[p1] <= height[p2])
                p1++;
            else
                p2--;
        }
        return maxVolume;
    }
};