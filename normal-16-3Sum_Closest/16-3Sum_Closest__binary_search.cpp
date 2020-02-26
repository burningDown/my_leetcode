class Solution {
private:
    int binaryFind(vector<int> &nums, int lflag, int rflag, int key)
    {
        // int lflag = 0, rflag = nums.size()-1;
        while(lflag < rflag-1)
        {
            if(nums[lflag]>=key)
                return lflag;
            else if(nums[rflag]<=key)
                return rflag;

            const int &mflag = (lflag + rflag) / 2;
            if(nums[mflag]<key)
            {
                lflag = mflag;
            }
            else if(nums[mflag]>key)
            {
                rflag = mflag;
            }
            else
                return mflag;
        }
        return lflag;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int &l = nums.size();
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for(int i=0;i<l-1;++i)
        {
            for(int j=i+1;j<l-1;++j)
            {
                const int flag = binaryFind(nums, j+1, l-1, target - nums[i] - nums[j]);
                const int &tempSum = nums[i] + nums[j] + nums[flag];
                if(abs(tempSum - target) < abs(sum - target))
                    sum = tempSum;
                
                if(flag < l-1)
                {
                    const int &tempSum = nums[i] + nums[j] + nums[flag+1];
                    if(abs(tempSum - target) < abs(sum - target))
                        sum = tempSum;
                }
            }
        }
        return sum;
    }
};