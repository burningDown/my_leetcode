class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        int l = tokens.size();
        for(int i=0;i<l;i++)
        {
            int num1, num2;
            switch(tokens[i][0])
            {
                case '+':
                    num1 = numStack.top();
                    numStack.pop();
                    num2 = numStack.top();
                    numStack.pop();
                    numStack.push(num2 + num1);
                    break;
                case '-':
                    if(tokens[i].size() > 1)
                    {
                        numStack.push(atoi(tokens[i].c_str()));
                    }
                    else
                    {
                        num1 = numStack.top();
                        numStack.pop();
                        num2 = numStack.top();
                        numStack.pop();
                        numStack.push(num2 - num1);
                    }
                    break;
                case '*':
                    num1 = numStack.top();
                    numStack.pop();
                    num2 = numStack.top();
                    numStack.pop();
                    numStack.push(num2 * num1);
                    break;
                case '/':
                    num1 = numStack.top();
                    numStack.pop();
                    num2 = numStack.top();
                    numStack.pop();
                    numStack.push(num2 / num1);
                    break;
                default:
                    numStack.push(atoi(tokens[i].c_str()));
                    break;
            }
        }
        return numStack.top();
    }
};