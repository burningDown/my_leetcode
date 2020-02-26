class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int &len = nums.size();
        int sum = nums[0] + nums[1] + nums[2];
        int l, r;
        sort(nums.begin(), nums.end());
        for(int i=0;i<len;++i)
        {
            l = i+1;
            r = len-1;
            while(l < r)
            {
                const int &tempSum = nums[i] + nums[l] + nums[r];
                if(abs(tempSum - target) < abs(sum - target))
                    sum = tempSum;
                
                if(tempSum < target)
                    ++l;
                else if(tempSum > target)
                    --r;
                else
                    return tempSum;
            }
        }
        return sum;
    }
};