class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        const int l = stones.size();
        int res = INT_MAX;
        if(K > 1 && (l - K) % (K - 1) != 0)
            return -1;
        
        vector<int> tempStones;

        if(l == 1)
            res = 0;
        for(int i=0;i<=l-K;i++)
        {
            tempStones.clear();
            int s = 0;
            for(int j=i;j<i+K;j++)
                s += stones[j];
            tempStones.insert(tempStones.end(), stones.begin(), stones.begin() + i);
            tempStones.push_back(s);
            tempStones.insert(tempStones.end(), stones.begin() + i + K, stones.end());
            res = min(res, mergeStones(tempStones, K) + s);
        }
        return res;
    }
};