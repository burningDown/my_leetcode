class Solution {
public:
    int myAtoi(string str) {
        long buffer = 0;
        bool minus = false;
        int state = 0;

        for(char c : str)
        {
            if(state == 100 || state == 200)
                break;
            
            switch(state)
            {
            case 0:
                if(c == '+')
                {
                    minus = false;
                    state = 1;
                }
                else if(c == '-')
                {
                    minus = true;
                    state = 1;
                }
                else if(c >= '0' && c <= '9')
                {
                    buffer = buffer * 10 + (c - '0');
                    state = 1;

                    if((minus && -buffer < INT_MIN) || (!minus && buffer > INT_MAX))
                    {
                        state = 200;
                    }
                }
                else if(c == ' ')
                {
                    state = 0;
                }
                else
                {
                    state = -100;
                }
                break;
            case 1:
                if(c >= '0' && c <= '9')
                {
                    buffer = buffer * 10 + (c - '0');
                    state = 1;

                    if((minus && -buffer < INT_MIN) || (!minus && buffer > INT_MAX))
                    {
                        state = 200;
                    }
                }
                else
                {
                    state = 100;
                }
                break;
            }
        }

        if(state == 200)
            return minus ? INT_MIN : INT_MAX;
        else
            return int(((-2)*minus+1) * buffer);
    }
};