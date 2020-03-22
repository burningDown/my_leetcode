class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        const int l = birth.size();
        int pBirth, pDeath;
        int max = 0, maxYear;

        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());

        for(pBirth=0, pDeath=0;pBirth<l;++pBirth)
        {
            while(death[pDeath] < birth[pBirth])
                ++pDeath;
            if(pBirth - pDeath + 1 > max)
            {
                max = pBirth - pDeath + 1;
                maxYear = birth[pBirth];
            }
        }
        return maxYear;
    }
};