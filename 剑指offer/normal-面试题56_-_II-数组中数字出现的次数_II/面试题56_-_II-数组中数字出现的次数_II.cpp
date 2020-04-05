class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto i : nums)
        {
            int temp = a;
            a = (a&(~b&(~i)))|((~a)&b&i);
            b = (~temp)&(b^i);
        }
        return b;
    }
};