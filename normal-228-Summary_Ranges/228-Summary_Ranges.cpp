class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        char buffer[100];
        int arrow = 0;
        int first, last;
        result.reserve(50);
        const int l = nums.size();

        if(nums.size() == 0)
            return result;

        result.push_back("");
        result[0].reserve(10);
        sprintf(buffer, "%d", nums[0]);
        result[0] += buffer;
        first = last = 0;

        for(int i=1;i<l;i++)
        {
            if(long(nums[i]) - nums[i-1] == 1)
                last = i;
            else
            {
                if(last > first)
                {
                    result[arrow] += "->";
                    sprintf(buffer, "%d", nums[last]);
                    result[arrow] += buffer;
                }

                result.push_back("");
                result[++arrow].reserve(10);
                sprintf(buffer, "%d", nums[i]);
                result[arrow] += buffer;
                first = last = i;
            }
        }

        if(last > first)
        {
            result[arrow] += "->";
            sprintf(buffer, "%d", nums[last]);
            result[arrow] += buffer;
        }
        return result;
    }
};