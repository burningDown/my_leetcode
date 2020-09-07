class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> numsMap;
        const int l = nums.size();
        int lasti = 0, lastj = 0;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for(int i=0;i<l;i++)
            numsMap[nums[i]]++;
        
        for(int i=0;i<l;i++)
        {
            if(i > 0 && nums[i] == lasti)
                continue;
            for(int j=i+1;j<l;j++)
            {
                if(j > i+1 && nums[j] == lastj)
                    continue;

                if(-nums[i] - nums[j] < nums[j])
                    break;
                else if(-nums[i] - nums[j] == nums[j])
                {
                    if(numsMap.find(-nums[i] - nums[j]) != numsMap.end())
                        if(nums[i] == nums[j] && numsMap[-nums[i] - nums[j]] > 2 || nums[i] != nums[j] && numsMap[-nums[i] - nums[j]] > 1)
                            res.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                }
                else
                {
                    if(numsMap.find(-nums[i] - nums[j]) != numsMap.end())
                        res.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                }
                lastj = nums[j];
            }
            lasti = nums[i];
        }
        return res;
    }
};