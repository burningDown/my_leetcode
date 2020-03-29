class Solution {
public:
    int strToInt(string str) {
        int res = 0;
        bool isNegative = false;
        bool numStart = false;

        for(char c : str)
        {
            if(!numStart)
            {
                if(c == ' ')
                    continue;
                else if(c == '-')
                {
                    numStart = true;
                    isNegative = true;
                }
                else if(c == '+')
                {
                    numStart = true;
                }
                else if(c>='0' && c<='9')
                {
                    numStart = true;
                    res *= 10;
                    res += (c-'0');
                }
                else
                    return 0;
            }
            else
            {
                if(c>='0' && c<='9')
                {
                    if(res > INT_MAX/10)
                    {
                        if(isNegative)
                            return INT_MIN;
                        else
                            return INT_MAX;
                    }
                    else if(res == INT_MAX/10 && INT_MAX-res*10 < c-'0')
                    {
                        if(isNegative)
                            return INT_MIN;
                        else
                            return INT_MAX;
                    }
                    else
                    {
                        res *= 10;
                        res += (c-'0');
                    }
                }
                else
                    break;
            }
        }
        return isNegative ? -res : res;
    }
};