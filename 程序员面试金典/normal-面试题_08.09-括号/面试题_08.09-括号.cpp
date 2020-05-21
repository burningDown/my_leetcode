class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0)
            return {""};
        if(n == 1)
            return {"()"};
        
        vector<string> result;

        for(int i=n;i>0;i--)
            for(string &l : generateParenthesis(i-1))
                for(string &r : generateParenthesis(n-i))
                    result.push_back(string("(") + l + string(")") + r);

        return result;
    }
};