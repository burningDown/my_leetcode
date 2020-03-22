class Solution {
public:
    int translateNum(int num) {
        int count = 0;

        if(num / 10 > 0)
            count += translateNum(num / 10);
        else
            return 1;
        if(num % 100 < 26 && num % 100 >=10)
        {
            if(num / 100 > 0)
            {
                count += translateNum(num / 100);
            }
            else
                count += 1;
        }
        return count;
    }
};