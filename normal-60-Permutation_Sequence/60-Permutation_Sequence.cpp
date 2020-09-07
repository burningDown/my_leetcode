class Solution {
private:
    string helper(int n, int k, int factorial, vector<bool> &mask)
    {
        int num = 0;
        int idx = 0;

        for(int i=0;i<mask.size();i++)
        {
            if(!mask[i])
            {
                if(n > 1 && idx == k/factorial || n == 1 && idx == 0)
                {
                    mask[i] = true;
                    num = i + 1;
                    break;
                }
                idx++;
            }
        }
        return n > 1 ? string(1, num + '0') + helper(n-1, k%factorial, factorial / (n-1), mask) : string(1, num + '0');
    }
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<bool> mask(n, false);

        for(int i=1;i<=n;i++)
        {
            factorial *= i;
        }

        return helper(n, k-1, factorial / n, mask);
    }
};