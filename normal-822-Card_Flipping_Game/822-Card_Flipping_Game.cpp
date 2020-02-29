class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int,int> numsMap;
        const int l = fronts.size();
        int min = 0, i;
        
        for(i=0;i<l;i++)
        {
            if(backs[i] == fronts[i])
            {
                numsMap[backs[i]]++;
            }
        }

        for(i=0;i<l;i++)
        {
            if(backs[i] != fronts[i])
            {
                if(numsMap[fronts[i]] == 0 && (fronts[i] < min || min == 0))
                {
                    min = fronts[i];
                }
                if(numsMap[backs[i]] == 0 && (backs[i] < min || min == 0))
                {
                    min = backs[i];
                }
            }
        }
        return min;
    }
};