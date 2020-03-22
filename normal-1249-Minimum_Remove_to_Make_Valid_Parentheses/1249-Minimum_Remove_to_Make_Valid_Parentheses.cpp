class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = s.size();
        int count = 0;
        int i = 0;
        while(i<l)
        {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')')
            {
                if(count == 0)
                {
                    s.erase(i, 1);
                    l--;
                    continue;
                }
                else
                    count--;
            }
            i++;
        }
        if(count > 0)
        {
            count = 0;
            i=l-1;
            while(i>=0)
            {
                if(s[i] == ')')
                    count++;
                else if(s[i] == '(')
                {
                    if(count == 0)
                    {
                        s.erase(i, 1);
                        i--;
                        l--;
                        continue;
                    }
                    else
                        count--;
                }
                i--;
            }
        }
        return s;
    }
};