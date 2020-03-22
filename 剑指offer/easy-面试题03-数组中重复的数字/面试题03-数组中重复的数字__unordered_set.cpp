class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int i : nums)
        {
            if(numSet.count(i))
                return i;
            else
                numSet.insert(i);
        }
        return 0;
    }
};