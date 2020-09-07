class Solution {
private:
    int KMP(string &source, string &pattern, int *next)
    {
        const int sl = source.size();
        const int pl = pattern.size();
        int i, j;

        next[0] = -1;
        for(i=1,j=0;i<pl;i++)
        {
            if(pattern[i] == pattern[j])
                next[i+1] = ++j;
            else
                next[i+1] = j = 0;
        }

        i = j = 0;
        while(i < sl && j < pl)
        {
            if(j == -1 || source[i] == pattern[j])
                i++, j++;
            else
                j = next[j];
        }

        return j == pl ? i - j : -1;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        int next[40];
        const int l = words.size();
        vector<string> res;

        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(i == j || words[j].size() <= words[i].size()) continue;
                if(KMP(words[j], words[i], next) >= 0)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};