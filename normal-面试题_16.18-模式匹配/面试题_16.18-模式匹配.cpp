class Solution {
private:
    bool backtrack(string &pattern, int pi, string &value, int vi, string &ptnA, bool constructA, string &ptnB, bool constructB)
    {
        if(pi >= pattern.size() && vi >= value.size())
            return true;
        if(pi >= pattern.size())
            return false;
        if(vi >= value.size())
        {
            char c = pattern[pi];
            if(c == 'a' && ptnA.size() == 0 || c == 'b' && ptnB.size() == 0)
            {
                for(int i=pi+1;i<pattern.size();i++)
                {
                    if(pattern[i] != c)
                        return false;
                }
                return true;
            }
            return false;
        }
        
        if(pattern[pi] == 'a')
        {
            if(constructA)
            {
                while((ptnA.size() > 0 && ptnA == ptnB) || !backtrack(pattern, pi+1, value, vi, ptnA, false, ptnB, constructB))
                {
                    if(vi >= value.size())
                    {
                        ptnA.clear();
                        return false;
                    }
                    
                    ptnA.push_back(value[vi]);
                    ++vi;
                }
                return true;
            }
            else
            {
                for(int i=0;i<ptnA.size();i++)
                {
                    if(ptnA[i] != value[i + vi])
                        return false;
                }
                return backtrack(pattern, pi+1, value, vi + ptnA.size(), ptnA, false, ptnB, constructB);
            }
        }
        if(pattern[pi] == 'b')
        {
            if(constructB)
            {
                while((ptnB.size() > 0 && ptnA == ptnB) || !backtrack(pattern, pi+1, value, vi, ptnA, constructA, ptnB, false))
                {
                    if(vi >= value.size())
                    {
                        ptnB.clear();
                        return false;
                    }
                    
                    ptnB.push_back(value[vi]);
                    ++vi;
                }
                return true;
            }
            else
            {
                for(int i=0;i<ptnB.size();i++)
                {
                    if(ptnB[i] != value[i + vi])
                        return false;
                }
                return backtrack(pattern, pi+1, value, vi + ptnB.size(), ptnA, constructA, ptnB, false);
            }
        }
        return false;
    }
public:
    bool patternMatching(string pattern, string value) {
        string ptnA, ptnB;
        return backtrack(pattern, 0, value, 0, ptnA, true, ptnB, true);
    }
};