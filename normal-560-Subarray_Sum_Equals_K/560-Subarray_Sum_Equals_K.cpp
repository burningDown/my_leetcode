class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap;
        const int l = nums.size();
        int sum = 0;
        int count = 0;

        sumMap[0] = 1;
        for(int i=0;i<l;i++)
        {
            sum += nums[i];
            if(sumMap.find(sum - k) != sumMap.end())
                count += sumMap[sum - k];
            
            sumMap[sum]++;
        }
        return count;
    }
};