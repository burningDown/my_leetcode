class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int l = A.size();
        int res = INT_MIN;
        int sumPre = 0, sumSuf = 0;
        vector<int> maxPre(l, 0);
        vector<int> maxSuf(l, 0);

        sumPre = maxPre[0] = A[0];
        sumSuf = maxSuf[l-1] = A[l-1];
        for(int i=1;i<l;i++)
        {
            sumPre += A[i];
            maxPre[i] = max(maxPre[i-1], sumPre);

            sumSuf += A[l-i-1];
            maxSuf[l-i-1] = max(maxSuf[l-i], sumSuf);
        }

        sumPre = 0;
        for(int i=0;i<l;i++)
        {
            sumPre = sumPre < 0 ? A[i] : sumPre + A[i];
            if(sumPre > res)
                res = sumPre;
        }
        for(int i=1;i<l;i++)
            res = max(res, maxSuf[i] + maxPre[i-1]);
        
        return res;
    }
};