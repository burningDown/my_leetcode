class Solution {
private:
    int mergeSort(vector<int> &nums, int start, int end)
    {
        static int buffer[50000+100];
        int b = 0;
        int count = 0;
        if(start >= end)
            return 0;
        int i = start, mid = (start + end) / 2;
        int j = mid + 1;
        count += mergeSort(nums, start, mid);
        count += mergeSort(nums, mid + 1, end);
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
            {
                buffer[b++] = nums[i];
                i++;
            }
            else
            {
                buffer[b++] = nums[j];
                j++;
                count += mid - i + 1;
            }
        }
        while(i <= mid)
        {
            buffer[b++] = nums[i];
            i++;
        }
        while(j <= end)
        {
            buffer[b++] = nums[j];
            j++;
        }
        for(i = 0;i<end-start+1;i++)
            nums[i+start] = buffer[i];
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};