class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i, j;
        for(i=0;i<n;i++)
        {
            for(j=m+i;j>0;j--)
            {
                if(B[i] < A[j-1])
                    A[j] = A[j-1];
                else
                    break;
            }
            A[j] = B[i];
        }
    }
};