class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int plus[2] = { 0 };
        const int l = nums.size();
        int i = 0, temp;
        vector<int> result;

        while(i < l+2)
        {
            if(i < l)
            {
                while(nums[i] != i+1 && nums[i] > 0)
                {
                    if(nums[i] <= l)
                    {
                        temp = nums[i];
                        nums[i] = nums[temp-1];
                        nums[temp-1] = temp;
                    }
                    else
                    {
                        temp = nums[i];
                        nums[i] = plus[temp - l - 1];
                        plus[temp - l - 1] = temp;
                    }
                }
            }
            else
            {
                while(plus[i-l] != i+1 && plus[i-l] > 0)
                {
                    if(plus[i-l] <= l)
                    {
                        temp = plus[i-l];
                        plus[i-l] = nums[temp-1];
                        nums[temp-1] = temp;
                    }
                    else
                    {
                        temp = plus[i-l];
                        plus[i-l] = plus[temp - l - 1];
                        plus[temp - l - 1] = temp;
                    }
                }
            }
            i++;
        }
        for(i=0;i<l;i++)
        {
            if(nums[i] == 0)
                result.push_back(i+1);
            if(result.size() >= 2)
                break;
        }
        for(i=0;i<2;i++)
        {
            if(result.size() >= 2)
                break;
            if(plus[i] == 0)
                result.push_back(i+l+1);
        }
        return result;
    }
};