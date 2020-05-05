class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> letterMap;
        const int l = s.size();
        for(int i=0;i<l;i++)
        {
            letterMap[s[i]]++;
        }
        if(l % 2 == 0)
        {
            for(auto it=letterMap.begin();it!=letterMap.end();it++)
            {
                if(it->second % 2 == 1)
                    return false;
            }
        }
        else
        {
            bool single = false;
            for(auto it=letterMap.begin();it!=letterMap.end();it++)
            {
                if(it->second % 2 == 1)
                {
                    if(!single)
                        single = true;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};