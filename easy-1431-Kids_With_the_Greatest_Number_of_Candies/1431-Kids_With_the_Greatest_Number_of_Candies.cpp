class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        const int l = candies.size();
        vector<bool> res(l, false);
        for(int i=0;i<l;i++)
        {
            if(maxCandies < candies[i])
                maxCandies = candies[i];
        }

        for(int i=0;i<l;i++)
        {
            if(candies[i] + extraCandies >= maxCandies)
                res[i] = true;
        }
        return res;
    }
};