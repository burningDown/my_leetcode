#define IS_DIGIT(x) x>='0' && x<='9' ? true : false

class Solution {
private:
    int lS(const char &c)
    {
        if(IS_DIGIT(c))
            return 1;
        else if(c == '+' || c == '-')
            return 8;
        else if(c == '.')
            return 6;
        else
            return -1;
    }
    int l1(const char &c)
    {
        if(IS_DIGIT(c))
            return 1;
        else if(c == 'e' || c == 'E')
            return 2;
        else if(c == '.')
            return 5;
        else if(c == 0)
            return 0;
        else
            return -1;
    }
    int l2(const char &c)
    {
        if(IS_DIGIT(c))
            return 3;
        else if(c == '+' || c == '-')
            return 7;
        else
            return -1;
    }
    int l3(const char &c)
    {
        if(IS_DIGIT(c))
            return 3;
        else if(c == 0)
            return 0;
        else
            return -1;
    }
    int l4(const char &c)
    {
        if(IS_DIGIT(c))
            return 4;
        else if(c == 0)
            return 0;
        else if(c == 'e' || c == 'E')
            return 2;
        else
            return -1;
    }
    int l5(const char &c)
    {
        if(IS_DIGIT(c))
            return 4;
        else if(c == 0)
            return 0;
        else if(c == 'e' || c == 'E')
            return 2;
        else
            return -1;
    }
    int l6(const char &c)
    {
        if(IS_DIGIT(c))
            return 4;
        else
            return -1;
    }
    int l7(const char &c)
    {
        if(IS_DIGIT(c))
            return 3;
        else
            return -1;
    }
    int l8(const char &c)
    {
        if(IS_DIGIT(c))
            return 1;
        else if(c == '.')
            return 6;
        else
            return -1;
    }
public:
    bool isNumber(string s) {
        int state = -100;
        char c;

        if(s[0] == ' ')
        {
            int i;
            for(i=0;s[i]==' ';++i)
                ;
            s.erase(0, i);
        }
        if(s[s.size()-1] == ' ')
        {
            int i;
            for(i=s.size()-1;s[i]==' ';--i)
                ;
            s.erase(i+1, s.size() - i - 1);
        }

        const int &l = s.size();
        if(l==0)
            return false;
        for(int i=0;i<=l;i++)
        {
            if(i == l)
                c = 0;
            else
                c = s[i];
            switch(state)
            {
            case -100:
                state = lS(c);
                break;
            case 1:
                state = l1(c);
                break;
            case 2:
                state = l2(c);
                break;
            case 3:
                state = l3(c);
                break;
            case 4:
                state = l4(c);
                break;
            case 5:
                state = l5(c);
                break;
            case 6:
                state = l6(c);
                break;
            case 7:
                state = l7(c);
                break;
            case 8:
                state = l8(c);
                break;
            case -1:
                return false;
            }
        }
        if(state == -1)
            return false;
        else
            return true;
    }
};