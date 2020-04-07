class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int change[110] = {0};
        const int l = birth.size();
        int alive = 0, max = 0, maxYear;

        for(int i=0;i<l;i++)
        {
            ++change[birth[i] - 1900];
            --change[death[i] - 1899];
        }

        for(int i=0;i<100;i++)
        {
            alive += change[i];
            if(alive > max)
            {
                max = alive;
                maxYear = i+1900;
            }
        }
        return maxYear;
    }
};