class Solution {
public:
    int longestPalindrome(string s) {
        char letterMap[60] = { 0 };
        int count = 0;
        for(char c : s)
        {
            letterMap[c - 'A']++;
            if(letterMap[c - 'A']%2 == 0)
                count += 2;
        }
        if(count < s.size())
            count++;
        return count;
    }
};