inline int max(int a, int b)
{
    return a > b ? a : b;
}
class Solution {
public:
    int massage(vector<int>& nums) {
        int count1 = 0, count2 = 0, current;
        const int l = nums.size();

        for(int i=0;i<l;i++)
        {
            current = max(nums[i] + count1, count2);
            count1 = count2;
            count2 = current;
        }
        return count2;
    }
};