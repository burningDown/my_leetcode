inline char toLower(char &c)
{
    return c - (c >= 'a' && c <='z' ? 32 : 0);
}

class Solution {
public:
    bool isPalindrome(string s) {
        const int l = s.size();
        int i = 0, j = l-1;

        while(i < j)
        {
            if(!(s[i] >= 'a' && s[i] <= 'z' || s[i] >='A' && s[i] <='Z' || s[i] >='0' && s[i] <='9'))
            {
                i++;
                continue;
            }
            if(!(s[j] >= 'a' && s[j] <= 'z' || s[j] >='A' && s[j] <='Z' || s[j] >='0' && s[j] <='9'))
            {
                j--;
                continue;
            }
            if(toLower(s[i]) != toLower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};