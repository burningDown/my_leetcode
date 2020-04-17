class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        const int l = big.size();
        unordered_map<int, int> smallMap;
        int unMapped = small.size();
        int p1 = 0, p2 = -1;
        vector<int> minRegion = {0, INT_MAX};

        for(int i : small)
            smallMap[i] = 0;

        p1 = 0;
        p2 = -1;
        while(p1 < l && p2 < l)
        {
            if(unMapped > 0)
            {
                p2++;
                if(p2 >= l)
                    break;
                if(smallMap.count(big[p2]))
                {
                    if(smallMap[big[p2]] == 0)
                        unMapped--;
                    smallMap[big[p2]]++;
                }
            }
            else
            {
                if(smallMap.count(big[p1]))
                {
                    smallMap[big[p1]]--;
                    if(smallMap[big[p1]] == 0)
                    {
                        unMapped++;

                        if(p2 - p1 < minRegion[1] - minRegion[0])
                        {
                            minRegion[0] = p1;
                            minRegion[1] = p2;
                        }
                    }
                }
                p1++;
            }
        }
        if(minRegion[1] == INT_MAX)
            return {};
        else
            return minRegion;
    }
};