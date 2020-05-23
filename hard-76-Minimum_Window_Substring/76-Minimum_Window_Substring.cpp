class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> sMap;
        const int l = s.size();
        int i = 0, j = 0, start = -1, end = l;
        int count = 0, currentCount = 0;

        for(char &c : t)
        {
            if(tMap[c] == 0)
                count++;
            tMap[c]++;
        }
        
        while(j < l)
        {
            if(tMap.find(s[j]) != tMap.end())
            {
                sMap[s[j]]++;
                if(sMap[s[j]] == tMap[s[j]])
                    currentCount++;

                while(i <= j && currentCount == count)
                {
                    if(j - i < end - start)
                    {
                        start = i;
                        end = j;
                    }
                    if(tMap.find(s[i]) != tMap.end())
                    {
                        sMap[s[i]]--;
                        if(sMap[s[i]] < tMap[s[i]])
                            currentCount--;
                    }
                    i++;
                }
            }
            j++;
        }
        return start >=0 ? s.substr(start, end - start + 1) : "";
    }
};