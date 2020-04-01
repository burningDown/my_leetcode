bool cmp(int a, int b)
{
    if(a == 0)
        return 0 < b;
    else if(b == 0)
        return a < 0;
    
    int la = (int)pow(10, (int)log10(a));
    int lb = (int)pow(10, (int)log10(b));
    if(la == lb)
        return a < b;
    else if(la > lb)
    {
        if(a/(la/lb) == b)
            return cmp(a%(la/lb), b);
        else
            return a/(la/lb) < b;
    }
    else
    {
        if(a == b/(lb/la))
            return cmp(a, b%(lb/la));
        else
            return a < b/(lb/la);
    }
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