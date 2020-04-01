class Solution {
private:
    int binaryFind(vector<int> &nums, int x)
    {
        const int l = nums.size();
        int i = 0, j = l-1;

        while(i <= j)
        {
            if(nums[(i + j)/2] < x)
                i = (i + j)/2+1;
            else if(nums[(i + j)/2] > x)
                j = (i + j)/2-1;
            else
                return (i + j)/2;
        }
        return INT_MIN;
    }
public:
    int search(vector<int>& nums, int target) {
        int idx = binaryFind(nums, target);
        if(idx == INT_MIN)
            return 0;
        const int l = nums.size();
        int count = 1;
        for(int i=idx-1;i>=0 && nums[i] == target;i--)
            count++;
        for(int i=idx+1;i<l && nums[i] == target;i++)
            count++;
        return count;
    }
};