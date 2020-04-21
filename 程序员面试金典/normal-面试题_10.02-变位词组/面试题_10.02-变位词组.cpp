class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        vector<vector<string>> result;
        for(string &s : strs)
        {
            string tempStrMap(26, 0);
            for(char &c : s)
            {
                tempStrMap[c-'a']++;
            }
            strMap[tempStrMap].push_back(s);
        }
        for(auto it=strMap.begin();it!=strMap.end();++it)
        {
            result.push_back(it->second);
        }
        return result;
    }
};