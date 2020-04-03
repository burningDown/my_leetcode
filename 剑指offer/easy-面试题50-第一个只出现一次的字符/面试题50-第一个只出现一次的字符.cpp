class Solution {
public:
    char firstUniqChar(string s) {
        int letterMap[30] = { 0 };
        for(char c : s)
            letterMap[c-'a']++;
        for(char c : s)
        {
            if(letterMap[c-'a'] == 1)
                return c;
        }
        return ' ';
    }
};