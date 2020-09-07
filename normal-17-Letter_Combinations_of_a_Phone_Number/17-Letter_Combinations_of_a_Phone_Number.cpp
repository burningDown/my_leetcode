class Solution {
private:
    static vector<string> lettersMap;
    vector<string> trackback(string &digits, int i)
    {
        if(i >= digits.size())
            return {""};
        vector<string> res;
        for(int j=0;j<lettersMap[digits[i]-'0'].size();j++)
        {
            string preRes = string(1, lettersMap[digits[i]-'0'][j]);
            for(auto subr : trackback(digits, i + 1))
                res.push_back(preRes + subr);
        }
        return res;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        return trackback(digits, 0);
    }
};

vector<string> Solution::lettersMap = 
{
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};