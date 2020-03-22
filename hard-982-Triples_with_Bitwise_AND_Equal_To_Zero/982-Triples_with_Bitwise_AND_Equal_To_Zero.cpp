class Solution {
public:
    int countTriplets(vector<int>& A) {
        int count = 0;
        const int l = A.size();
        for(int i=0;i<l;i++)
        {
            for(int j=i;j<l;j++)
            {
                if((A[i] & A[j]) == 0)
                {
                    if(i == j)
                        count += (3*(l-j-1) + 1);
                    else
                        count += (6*(l-j-1) + 3);
                }
                else
                {
                    for(int k=j;k<l;k++)
                    {
                        if((A[i] & A[j] & A[k]) == 0)
                        {
                            if(i == j)
                            {
                                if(j == k)
                                    count += 1;
                                else
                                    count += 3;
                            }
                            else
                            {
                                if(j == k)
                                    count += 3;
                                else
                                    count += 6;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};