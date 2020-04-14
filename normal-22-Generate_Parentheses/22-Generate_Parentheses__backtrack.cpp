class Solution {
private:
    void generate(vector<string> &result, string &expression, int left, int n)
    {
        if(left == 0 && n == 0)
        {
            result.push_back(expression);
            return;
        }

        if(n > 0)
        {
            expression.push_back('(');
            generate(result, expression, left+1, n-1);
            expression.pop_back();
        }
        if(left > 0)
        {
            expression.push_back(')');
            generate(result, expression, left-1, n);
            expression.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        string expression;
        vector<string> result;
        
        expression.reserve(n * 2 + 5);
        generate(result, expression, 0, n);

        return result;
    }
};