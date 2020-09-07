class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> subStrMap;
        const int l = s.size();
        int lettersMap[26] = { 0 };
        int count = 0;
        int res = 0;

        for(int i=0;i<minSize-1;i++)
        {
            if(lettersMap[s[i]-'a'] == 0)
                count++;
            lettersMap[s[i]-'a']++;
        }

        for(int i=0;i<l-minSize+1;i++)
        {
            if(lettersMap[s[i+minSize-1]-'a'] == 0)
                count++;
            lettersMap[s[i+minSize-1]-'a']++;

            if(count <= maxLetters)
            {
                string sub = s.substr(i, minSize);
                subStrMap[sub]++;
                res = max(res, subStrMap[sub]);
            }
            lettersMap[s[i]-'a']--;
            if(lettersMap[s[i]-'a'] == 0)
                count--;
        }
        return res;
    }
};