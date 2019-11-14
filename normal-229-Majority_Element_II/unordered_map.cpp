#include<unordered_map>
unordered_map<int, int> countMap;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int l = nums.size();
        int flag = l/3;
        vector<int> result;
        for(int i=0;i<l;i++)
        {
            countMap[nums[i]] = 0;
        }
        for(int i=0;i<l;i++)
        {
            int num = nums[i];
            if(countMap[num] >= 0)
            {
                countMap[num]++;
                if(countMap[num] > flag)
                {
                    result.push_back(num);
                    countMap[num] = -1;
                }
            }
        }
        return result;
    }
};