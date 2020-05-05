class Solution {
private:
    int parseNum(string &s, int &idx)
    {
        int num = 0;
        const int l = s.size();
        for(;idx<l;idx++)
        {
            if(s[idx] >= '0' && s[idx] <= '9')
            {
                num *= 10;
                num += s[idx] - '0';
            }
            else if(s[idx] == ' ') continue;
            else break;
        }
        return num;
    }

    int operate(char op, int num1, int num2)
    {
        int res;
        switch(op)
        {
            case '+': res = num1 + num2; break;
            case '-': res = num1 - num2; break;
            case '*': res = num1 * num2; break;
            case '/': res = num1 / num2; break;
        }
        return res;
    }
public:
    int calculate(string s) {
        int opStack[5] = { 0 };
        int o = 0;

        int numStack[5] = { 0 };
        int n = 0;

        int idx = 0;
        const int l = s.size();

        numStack[n++] = parseNum(s, idx);
        
        while(idx < l)
        {
            if(s[idx] == ' ')
            {
                idx++;
                continue;
            }
            if(s[idx] == '+' || s[idx] == '-')
            {
                if(o > 0)
                {
                    numStack[n-2] = operate(opStack[o-1], numStack[n-2], numStack[n-1]);
                    n--, o--;
                }
                
                opStack[o++] = s[idx++];
                numStack[n++] = parseNum(s, idx);
            }
            else
            {
                opStack[o++] = s[idx++];
                numStack[n++] = parseNum(s, idx);

                numStack[n-2] = operate(opStack[o-1], numStack[n-2], numStack[n-1]);
                n--, o--;
            }
        }

        if(o > 0)
        {
            numStack[n-2] = operate(opStack[o-1], numStack[n-2], numStack[n-1]);
            n--, o--;
        }

        return numStack[0];
    }
};