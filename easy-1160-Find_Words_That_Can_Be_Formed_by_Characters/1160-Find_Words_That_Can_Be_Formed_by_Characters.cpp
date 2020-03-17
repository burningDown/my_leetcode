class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        char letterMap[26] = { 0 };
        int i;
        int count = 0;
        for(char c : chars)
            letterMap[c - 'a']++;
        for(string s : words)
        {
            for(i = 0;i < s.size();i++)
            {
                letterMap[s[i]-'a']--;
                if(letterMap[s[i]-'a'] < 0)
                    break;
            }
            if(i == s.size())
            {
                count += i;
                i--;
            }
            for(int j=0;j<=i;j++)
            {
                letterMap[s[j]-'a']++;
            }
        }
        return count;
    }
};