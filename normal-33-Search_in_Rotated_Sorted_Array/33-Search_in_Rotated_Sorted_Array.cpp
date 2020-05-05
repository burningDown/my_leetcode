class Solution {
private:
    int binarySearch(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        int mid;

        if(nums[0] == target)
            return 0;
        
        while(i < j)
        {
            mid = (i + j) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[0])
            {
                if(nums[mid] > nums[0])
                {
                    if(nums[mid] < target)
                        i = mid + 1;
                    else
                        j = mid;
                }
                else
                    j = mid;
            }
            else
            {
                if(nums[mid] < nums[0])
                {
                    if(nums[mid] < target)
                        i = mid + 1;
                    else
                        j = mid;
                }
                else
                    i = mid + 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        return binarySearch(nums, target);
    }
};