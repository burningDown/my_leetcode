class Solution {
public:
    string reverseWords(string s) {
        const int l = s.size();
        int i, end = l;
        string result;
        result.reserve(s.size() + 5);
        for(i=l-1;i>=0;i--)
        {
            for(;i>=0;i--)
            {
                if(s[i] == ' ')
                {
                    if(result.size() > 0)
                        result += ' ';
                    result += s.substr(i+1, end - i - 1);
                    for(;i>=0;i--)
                    {
                        if(s[i] != ' ')
                            break;
                    }
                    end = i + 1;
                    break;
                }
            }
        }
        if(end > 0)
        {
            if(result.size() > 0)
                result += ' ';
            result += s.substr(0, end);
        }
        return result;
    }
};