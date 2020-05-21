class Solution {
private:
    int partition(vector<int> &nums, int start, int end, int acc)
    {
        if(start > end)
            return 0;

        if(acc > 0 || start == end)
            return acc;

        int res = acc;
        int tempAcc = acc;
        for(int i=start;i<=end;i++)
        {
            tempAcc /= nums[i];
            if(tempAcc > 0)
            {
                res = max(res, tempAcc);
                break;
            }
        }

        tempAcc = acc;
        for(int i=end;i>=start;i--)
        {
            tempAcc /= nums[i];
            if(tempAcc > 0)
            {
                res = max(res, tempAcc);
                break;
            }
        }
        return res;
    }
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int acc = 1;
        int start = 0;
        const int l =  nums.size();
        for(int i=0;i<l;i++)
        {
            if(nums[i] == 0)
            {
                res = max(res, partition(nums, start, i-1, acc));
                start = i+1;
                acc = 1;
            }
            else
                acc *= nums[i];
        }
        res = max(res, partition(nums, start, l-1, acc));

        if(start > 0)
            res = max(res, 0);
        return res;
    }
};
};