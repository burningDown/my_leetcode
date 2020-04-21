class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int countOdd = 0;
        int count = 0;
        int p1 = 0, p2 = 0, lp1 = -1, lp2 = -1;
        const int l = nums.size();
        
        while(p2 <= l)
        {
            if(countOdd == k)
            {
                if(p2 < l && !(nums[p2] & 1))
                    p2++;
                else
                {
                    if(nums[p1] & 1)
                    {
                        count += (p1 - lp1) * (p2 - lp2);
                        lp1 = p1;
                        countOdd--;
                    }
                    p1++;
                }
            }
            else
            {
                if(p2 >= l)
                    break;
                
                if(nums[p2] & 1)
                {
                    lp2 = p2;
                    countOdd++;
                }
                p2++;
            }
        }
        return count;
    }
};