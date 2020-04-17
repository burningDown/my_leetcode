class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        unordered_map<char, vector<int>> letterMap;
        const int ls = big.size();
        vector<vector<int>> result;
        vector<int> pos;
        bool isMatch;
        for(int i=0;i<ls;i++)
        {
            letterMap[big[i]].push_back(i);
        }
        for(string &s : smalls)
        {
            pos.clear();
            if(letterMap.count(s[0]) > 0)
            {
                for(int idx : letterMap[s[0]])
                {
                    if(ls - idx >= s.size())
                    {
                        isMatch = true;
                        for(int i=0;i<s.size();i++)
                        {
                            if(s[i] != big[i+idx])
                            {
                                isMatch = false;
                                break;
                            }
                        }
                        if(isMatch)
                        {
                            pos.push_back(idx);
                        }
                    }
                }
            }
            result.push_back(pos);
        }
        return result;
    }
};