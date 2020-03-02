class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n)
        {
            if(n % 26 == 0)
            {
                result = 'Z' + result;
                n -= 1;
            }
            else
            {
                result = char('A'+n%26-1) + result;
            }
            n /= 26;
        }
        return result;
    }
};