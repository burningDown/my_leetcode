class Solution {
private:
    bool trackback(unordered_map<string, bool> &dpMap, string &numMap, int sum, int maxChoosableInteger, int desiredTotal)
    {
        if(dpMap.find(numMap) != dpMap.end())
            return dpMap[numMap];
        
        for(int i=1;i<=maxChoosableInteger;i++)
        {
            if(numMap[i] == '0')
            {
                numMap[i] = '1';
                if(sum + i >= desiredTotal || !trackback(dpMap, numMap, sum + i, maxChoosableInteger, desiredTotal))
                {
                    numMap[i] = '0';

                    dpMap[numMap] = true;
                    return true;
                }
                numMap[i] = '0';
            }
        }

        dpMap[numMap] = false;
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        string numMap(maxChoosableInteger + 1, '0');
        unordered_map<string, bool> dpMap;

        if(maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal)
            return false;

        return trackback(dpMap, numMap, 0, maxChoosableInteger, desiredTotal);
    }
};