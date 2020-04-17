class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        const int l = nums.size();
        vector<vector<int>> result;

        for(int i=0;i<l;i++)
        {
            numMap[nums[i]]++;
        }
        
        for(int i=0;i<l;i++)
        {
            if(numMap[nums[i]] > 0)
            {
                numMap[nums[i]]--;
                if(numMap.count(target-nums[i]) > 0 && numMap[target-nums[i]] > 0)
                {
                    result.push_back({nums[i], target-nums[i]});
                    numMap[target-nums[i]]--;
                }
                else
                {
                    numMap[nums[i]]++;
                }
            }
        }
        return result;
    }
};