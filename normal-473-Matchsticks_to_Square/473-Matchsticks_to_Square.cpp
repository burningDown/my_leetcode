class Solution {
private:
    bool trackback(vector<int> &nums, unordered_map<unsigned int, bool> &dpMap, unsigned int &numsMask, int picked, int width, int round)
    {
        if(dpMap.find(numsMask) != dpMap.end())
            return dpMap[numsMask];

        if(round >= 4)
            return true;
        
        if(picked < width)
        {
            const int l = nums.size();
            for(int i=0;i<l;i++)
            {
                if(!(numsMask & (1 << i)))
                {
                    numsMask |= (1 << i);
                    picked += nums[i];
                    if(trackback(nums, dpMap, numsMask, picked, width, round))
                    {
                        picked -= nums[i];
                        numsMask &= ~(1 << i);
                        dpMap[numsMask] = true;
                        return true;
                    }
                    picked -= nums[i];
                    numsMask &= ~(1 << i);
                }
            }
        }
        else if(picked == width)
        {
            if(trackback(nums, dpMap, numsMask, 0, width, round + 1))
            {
                dpMap[numsMask] = true;
                return true;
            }
        }

        dpMap[numsMask] = false;
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        const int l = nums.size();
        unordered_map<unsigned int, bool> dpMap;
        
        for(int i=0;i<l;i++)
            sum += nums[i];
        if(sum % 4 != 0 || sum == 0)
            return false;

        // vector<string> numsMask(nums.size(), '0');
        unsigned int numsMask = 0;
        return trackback(nums, dpMap, numsMask, 0, sum / 4, 1);
    }
};