class Solution {
private:
    void traverse(string &S, unordered_set<string> &resultSet, string &inst, int idx)
    {
        const int l = S.size();
        if(idx >= l)
        {
            resultSet.insert(inst);
            return;
        }

        for(int i=0;i<l;i++)
        {
            if(inst[i] == 0)
            {
                inst[i] = S[idx];
                traverse(S, resultSet, inst, idx+1);
                inst[i] = 0;
            }
        }
    }
public:
    vector<string> permutation(string S) {
        unordered_set<string> resultSet;
        const int l = S.size();
        string inst(S.size(), 0);

        traverse(S, resultSet, inst, 0);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};