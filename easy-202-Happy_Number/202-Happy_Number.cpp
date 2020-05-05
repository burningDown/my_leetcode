class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numSet;
        int m;

        while(numSet.count(n) == 0)
        {
            numSet.insert(n);
            m = n;
            n = 0;
            for(;m > 0;m /= 10)
                n += (m % 10) * (m % 10);
            if(n == 1)
                return true;
        }

        return false;
    }
};