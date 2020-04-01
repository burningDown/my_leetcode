class Solution {
private:
    int quickFind(vector<int> &nums, int start, int l, int k)
    {
        int pIdx = rand() % l + start;

        int partition = nums[pIdx];
        nums[pIdx] = nums[start];

        int i = start, j = start + l - 1;
        while(i < j)
        {
            while(i < j)
            {
                if(nums[j] < partition)
                {
                    nums[i] = nums[j];
                    i++;
                    break;
                }
                j--;
            }
            while(i < j)
            {
                if(nums[i] > partition)
                {
                    nums[j] = nums[i];
                    j--;
                    break;
                }
                i++;
            }
        }
        nums[i] = partition;
        if(i == nums.size() - k)
            return nums[i];
        else if(i > nums.size() - k)
            return quickFind(nums, start, i - start, k);
        else
            return quickFind(nums, i+1, start + l - i - 1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickFind(nums, 0, nums.size(), k);
    }
};