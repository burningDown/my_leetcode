class Solution {
private:
    void traverse(string &S, int lettersMap[], vector<string> &result, string &inst, int idx)
    {
        const int l = S.size();
        if(idx >= l)
        {
            result.push_back(inst);
            return;
        }
        int freq = lettersMap[S[idx] - 'A'];
        lettersMap[S[idx] - 'A']++;

        for(int i=0;i<l;i++)
        {
            if(freq == 0)
            {
                if(inst[i] == 0)
                {
                    inst[i] = S[idx];
                    traverse(S, lettersMap, result, inst, idx+1);
                    inst[i] = 0;
                }
            }
            else if(inst[i] == S[idx])
                freq--;
        }

        lettersMap[S[idx] - 'A']--;
    }
public:
    vector<string> permutation(string S) {
        int lettersMap[60] = { 0 };
        vector<string> result;
        const int l = S.size();
        string inst(S.size(), 0);

        traverse(S, lettersMap, result, inst, 0);
        return result;
    }
};