class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int l = A.size();
        int sum = 0;
        int res = INT_MIN;
        for(int start=0;start<l;start++)
        {
            sum = 0;
            for(int i=0;i<l;i++)
            {
                sum = sum < 0 ? A[(start + i) % l] : sum + A[(start + i) % l];
                if(sum > res)
                    res = sum;
            }
        }
        return res;
    }
};