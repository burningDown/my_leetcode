class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int letterMap[26] = { 0 };
        for(char &c : s1)
            letterMap[c-'a']++;
        for(char &c : s2)
        {
            letterMap[c-'a']--;
            if(letterMap[c-'a'] < 0)
                return false;
        }
        return true;
    }
};