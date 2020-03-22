class Solution {
private:
    unordered_set<string> wordSet;
    unordered_set<int> idxSet;
    string re;
    vector<string> result;
    void backtrack(string &s, int idx)
    {
        if(wordSet.count(re) != 0)
            return;

        wordSet.insert(re);

        if(idx == s.size()-1)
        {
            result.push_back(re);
        }
        else
        {
            for(int i=0;i<s.size();i++)
            {
                if(idxSet.count(i) != 0)
                    continue;
                re.push_back(s[i]);
                idxSet.insert(i);
                backtrack(s, idx+1);
                re.pop_back();
                idxSet.erase(i);
            }
        }
    }
public:
    vector<string> permutation(string s) {
        result.reserve(40000);
        re.reserve(s.size()*2);
        for(int i=0;i<s.size();i++)
        {
            if(idxSet.count(i) != 0)
                continue;
            re.push_back(s[i]);
            idxSet.insert(i);
            backtrack(s, 0);
            re.pop_back();
            idxSet.erase(i);
        }
        return result;
    }
};