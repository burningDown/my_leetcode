class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 1;
        int maxLength = 1;
        const int l = s.size();
        unordered_set<int> letterSet;
        if(l < 2)
            return s.size();
        letterSet.insert(s[i]);
        while(j < l)
        {
            if(letterSet.count(s[j]) == 1)
            {
                while(letterSet.count(s[j]) == 1)
                    letterSet.erase(s[i++]);
            }
            else if(maxLength < j - i + 1)
                maxLength = j - i + 1;
            letterSet.insert(s[j++]);
        }
        return maxLength;
    }
};