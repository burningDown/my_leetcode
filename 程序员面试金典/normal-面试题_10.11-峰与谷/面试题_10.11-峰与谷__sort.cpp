class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> numsCopy(nums.begin(), nums.end());
        const int l = nums.size();

        sort(numsCopy.begin(), numsCopy.end());

        int n = 0, i = 0, j = l/2;
        while(n < l)
        {
            nums[n++] = numsCopy[j++];

            if(n >= l)
                break;
            
            nums[n++] = numsCopy[i++];
        }
    }
};