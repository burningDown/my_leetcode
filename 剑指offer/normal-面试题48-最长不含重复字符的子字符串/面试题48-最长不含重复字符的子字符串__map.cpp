class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 1;
        int maxLength = 1;
        const int l = s.size();
        int letterMap[200];
        memset(letterMap, -1, 200 * sizeof(int));
        if(l < 2)
            return s.size();
        letterMap[s[i]] = i;
        while(j < l)
        {
            if(letterMap[s[j]] >= i)
                i = letterMap[s[j]] + 1;
            if(maxLength < j - i + 1)
                maxLength = j - i + 1;
            letterMap[s[j]] = j;
            j++;
        }
        return maxLength;
    }
};