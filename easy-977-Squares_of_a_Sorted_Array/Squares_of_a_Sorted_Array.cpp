class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = A.size();
        vector<int> result(l);
        int i=0,j=0;
        for(;i<l&&A[i]<0;i++);
        j=i--;
        for(int k=0;k<l;k++)
        {
            if(j>=l||(i>=0&&-A[i]<A[j]))
            {
                result[k] = A[i]*A[i];
                i--;
            }
            else
            {
                result[k] = A[j]*A[j];
                j++;
            }
        }
        return result;
    }
};