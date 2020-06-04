class Solution {
private:
    int decodeNum(string &s, int &start, int l)
    {
        int repeat = 0;
        int i;
        for(i=start;i<l;i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                repeat = repeat * 10 + s[i] - '0';
            else
                break;
        }
        start = i;
        return repeat;
    }
    string repeatString(string &s, int repeat)
    {
        string buffer;

        buffer.reserve(s.size() * repeat);
        for(int i=0;i<repeat;i++)
            buffer += s;
        
        return buffer;
    }

    string helper(string &s, int &start, int l)
    {
        int repeat = 0;
        int i = start;
        string res;
        while(i < l)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                repeat = decodeNum(s, i, l);
                i++;
                string subString = helper(s, i, l);
                i++;
                res += repeatString(subString, repeat);
            }
            else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            {
                res += s[i];
                i++;
            }
            else
                break;
        }
        start = i;
        return res;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i, s.size());
    }
};