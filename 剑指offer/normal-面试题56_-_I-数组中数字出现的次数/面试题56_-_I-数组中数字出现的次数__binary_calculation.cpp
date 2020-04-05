class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a = 0;
        vector<int> result(2, 0);
        for(int i : nums)
            a ^= i;
        int k = a&(-a);
        for(int i : nums)
        {
            if(i & k)
                result[0] ^= i;
            else
                result[1] ^= i;
        }
        return result;
    }
};