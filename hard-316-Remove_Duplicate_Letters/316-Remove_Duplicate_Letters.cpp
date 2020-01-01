class Solution {
private:
    char resultBuf[1000];
    int r;
    int countMap[26];
    bool visited[26];
public:
    Solution(): resultBuf({0}), r(0), countMap({0}), visited({0}){}
    string removeDuplicateLetters(string s) {
        int l = s.size();
        char c;
        for(int i=0;i<l;i++)
            countMap[s[i]-'a']++;
        for(int i=0;i<l;i++)
        {
            c = s[i];
            countMap[c-'a']--;
            if(visited[c-'a'])
                continue;
            visited[c-'a'] = true;
            while(r>0 && resultBuf[r-1]>c && countMap[resultBuf[r-1]-'a']>0)
            {
                visited[resultBuf[--r]-'a'] = false;
                resultBuf[r] = 0;
            }
            resultBuf[r++] = c;
        }
        return string(resultBuf);
    }
};