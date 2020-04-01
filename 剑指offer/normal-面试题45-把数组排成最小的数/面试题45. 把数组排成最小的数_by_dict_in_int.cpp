bool cmp(int a, int b)
{
    if(a == 0 || b == 0)
        return a < b;
    const int la = (int)pow(10, (int)log10(a));
    const int lb = (int)pow(10, (int)log10(b));

    return (long long)(a) * lb * 10 + b < a + (long long)(b) * la * 10;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        string result;
        result.reserve(1000);
        
        sort(nums.begin(), nums.end(), cmp);
        for(int i : nums)
            result += to_string(i);
        return result;
    }
};