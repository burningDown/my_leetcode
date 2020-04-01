bool cmp(string s1, string s2)
{
    return s1 + s2 < s2 + s1;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> numsInString;
        string result;
        result.reserve(1000);
        numsInString.reserve(nums.size()+5);
        for(int i : nums)
            numsInString.push_back(to_string(i));
        sort(numsInString.begin(), numsInString.end(), cmp);
        for(string &s : numsInString)
            result += s;
        return result;
    }
};