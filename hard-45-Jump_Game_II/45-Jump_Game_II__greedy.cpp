class Solution {
public:
    int jump(vector<int>& nums) {
        int maxIdx = 0;
        int currentMaxIdx = 0;
        int step = 0;
        const int l = nums.size();

        for(int i=0;i<l-1;i++)
        {
            maxIdx = max(maxIdx, i + nums[i]);
            if(i == currentMaxIdx)
            {
                step++;
                currentMaxIdx = maxIdx;
            }
        }

        return step;
    }
};