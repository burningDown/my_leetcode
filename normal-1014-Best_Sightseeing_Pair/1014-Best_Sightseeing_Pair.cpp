class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        const int l = A.size();
        int maxi = A[0], maxj = A[1] - 1;
        int res = 0;

        for(int j=1;j<l;j++)
        {
            maxj = A[j] - j;
            maxi = max(maxi, A[j-1] + j-1);
            res = max(res, maxi + maxj);
        }
        
        return res;
    }
};