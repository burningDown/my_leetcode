class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 1;
        int flag = 1, continues = 0;
        const int l = ratings.size();
        for(int i=0;i<l-1;i++)
        {
            if(ratings[i+1] < ratings[i])
                continues++;
            else if(ratings[i+1] > ratings[i])
            {
                if(continues == 0)
                {
                    flag++;
                    count += flag;
                }
                else
                {
                    count += continues*(continues+1)/2;
                    if(continues+1 > flag)
                    {
                        count -= flag;
                        count += continues+1;
                    }
                    count += 2;
                    continues = 0;
                    flag = 2;
                }
            }
            else
            {
                if(continues == 0)
                {
                    count += 1;
                    flag = 1;
                }
                else
                {
                    count += continues*(continues+1)/2;
                    if(continues+1 > flag)
                    {
                        count -= flag;
                        count += continues+1;
                    }
                    count += 1;
                    continues = 0;
                    flag = 1;
                }
            }
        }
        if(continues != 0)
        {
            count += continues*(continues+1)/2;
            if(continues+1 > flag)
            {
                count -= flag;
                count += continues+1;
            }
        }
        return count;
    }
};