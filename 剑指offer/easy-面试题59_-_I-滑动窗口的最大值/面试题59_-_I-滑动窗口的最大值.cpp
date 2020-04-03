class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxQueue;
        const int l = nums.size();
        vector<int> result;
        int i;

        if(k == 0)
            return result;

        result.reserve(nums.size() - k + 5);
        for(i=0;i<k;i++)
        {
            while(!maxQueue.empty() && maxQueue.back() < nums[i])
                maxQueue.pop_back();
            maxQueue.push_back(nums[i]);
        }
        result.push_back(maxQueue.front());
        for(;i<l;i++)
        {
            while(!maxQueue.empty() && maxQueue.back() < nums[i])
                maxQueue.pop_back();
            maxQueue.push_back(nums[i]);

            if(maxQueue.front() == nums[i-k])
                maxQueue.pop_front();

            result.push_back(maxQueue.front());
        }
        return result;
    }
};