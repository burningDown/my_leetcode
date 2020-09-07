class Solution {
private:
    int trackback(vector<int> &slices, unordered_map<string, int> &dpMap, vector<pair<int, int>> &linkIdxList, string &mask, int start, int left, int l)
    {
        if(dpMap.find(mask) != dpMap.end())
            return dpMap[mask];
        
        if(left == 0)
            return 0;

        int res = 0;
        int me, bob, alice;
        
        // for(int i=0;i<l;i++)
        for(int i=start;;)
        {
            if(mask[i] == '0')
            {
                mask[i] = '1';
                me = i;

                auto &myNode = linkIdxList[me];
                bob = myNode.second;
                alice = myNode.first;

                if(left - slices[me] - slices[bob] - slices[alice] > 0)
                {
                    auto &bobNode = linkIdxList[myNode.second];
                    auto &newRightNode = linkIdxList[bobNode.second];

                    myNode.second = bobNode.second;
                    newRightNode.first = me;
                    mask[bob] = '1';

                    auto &aliceNode = linkIdxList[myNode.first];
                    auto &newLeftNode = linkIdxList[aliceNode.first];

                    myNode.first = aliceNode.first;
                    newLeftNode.second = me;
                    mask[alice] = '1';

                    newLeftNode.second = bobNode.second;
                    newRightNode.first = aliceNode.first;

                    res = max(res, slices[me] + trackback(slices, dpMap, linkIdxList, mask, bobNode.second, left - slices[me] - slices[bob] - slices[alice], l));

                    newLeftNode.second = alice;
                    newRightNode.first = bob;
                    myNode.first = alice;
                    myNode.second = bob;

                    mask[bob] = '0';
                    mask[alice] = '0';
                }
                else
                {
                    res = max(res, slices[me]);
                }
                mask[me] = '0';
            }
            i = linkIdxList[i].second;
            if(i == start)
                break;
        }

        dpMap[mask] = res;
        return res;
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        const int l = slices.size();
        string mask(l, '0');
        unordered_map<string, int> dpMap;
        vector<pair<int, int>> linkIdxList(l);
        int left = 0;
        for(int i=0;i<l;i++)
            left += slices[i];
        for(int i=0;i<l;i++)
        {
            linkIdxList[i].first = (i-1+l) % l;
            linkIdxList[i].second = (i+1) % l;
        }
        return trackback(slices, dpMap, linkIdxList, mask, 0, left, l);
    }
};