class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum;
        const int &l = nums.size();
        sum = nums[0] + nums[1] + nums[2];
        for(int i=0;i<l;i++)
        {
            for(int j=i+1;j<l;j++)
            {
                for(int k=j+1;k<l;k++)
                {
                    const int &tempSum = nums[i] + nums[j] + nums[k];
                    if(abs(tempSum - target) < abs(sum - target))
                        sum = tempSum;
                }
            }
        }
        return sum;
    }
};