class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i, end;

        if(s.size() == 0)
            return result;

        result.reserve(100);

        i = s.size() - 1;
        while(i >= 0)
        {
            while(i >= 0)
            {
                if(s[i] != ' ')
                    break;
                i--;
            }
            if(i < 0)
                break;
            end = i;
            while(i >= 0)
            {
                if(s[i] == ' ')
                    break;
                i--;
            }
            result += s.substr(i+1, end - i);
            result += ' ';
            i--;
        }
        if(result.size() > 0)
            result.pop_back();
        return result;
    }
};