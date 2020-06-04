class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
            return false;
        
        int sum = -num;
        int sq = sqrt(num);
        for(int i=1;i<=sq;i++)
        {
            if(num % i == 0)
            {
                sum += i;
                sum += num / i;
            }
        }

        return sum == num;
    }
};