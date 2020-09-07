class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int temperaturesMap[101] = { 0 };
        const int l = T.size();
        int minIdx;
        vector<int> res(l, 0);

        for(int i=l-1;i>=0;i--)
        {
            temperaturesMap[T[i]] = i;
            minIdx = l;
            for(int j=T[i] + 1;j<=100;j++)
                if(temperaturesMap[j] > 0)
                    minIdx = min(minIdx, temperaturesMap[j]);
            if(minIdx < l)
                res[i] = minIdx - i;
        }

        return res;
    }
};