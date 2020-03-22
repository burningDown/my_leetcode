class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        const int l = A.size();
        int count = 0;
        sort(A.begin(), A.end());
        for(int i=1;i<l;i++)
        {
            if(A[i] <= A[i-1])
            {
                count +=(A[i-1]+1-A[i]);
                A[i] = A[i-1]+1;
            }
        }
        return count;
    }
};