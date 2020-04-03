class Solution {
public:
    string replaceSpace(string s) {
        string result;
        result.reserve(s.size() * 3);
        for(char c : s)
        {
            if(c == ' ')
                result += "%20";
            else
                result += c;
        }
        return result;
    }
};