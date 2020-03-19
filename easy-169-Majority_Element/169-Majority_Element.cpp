class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> numMap;
        int major = nums[0];
        for(int i : nums)
        {
            numMap[i]++;
            if(numMap[i] > numMap[major])
                major = i;
        }
        return major;
    }
};