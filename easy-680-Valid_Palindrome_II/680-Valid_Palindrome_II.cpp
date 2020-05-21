class Solution {
private:
    bool trackOnce(string &s, int start, int end, bool deleted)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return !deleted && (trackOnce(s, start + 1, end, true) || trackOnce(s, start, end - 1, true));

            start++;
            end--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return trackOnce(s, 0, s.size()-1, false);
    }
};