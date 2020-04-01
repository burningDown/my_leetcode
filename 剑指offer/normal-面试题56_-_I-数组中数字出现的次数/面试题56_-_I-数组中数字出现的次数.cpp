class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int l = nums.size();
        int i=0;
        vector<int> result;
        while(i<l)
        {
            if(i == l-1 || nums[i] != nums[i+1])
            {
                result.push_back(nums[i]);
                i++;
            }
            else
                i+=2;
        }
        return result;
    }
};