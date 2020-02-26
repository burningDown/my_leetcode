class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> freqMap;
        vector<int> sortedV(k);
        int s = 0, i, j, temp;

        const int l = nums.size();
        
        for(i=0;i<l;++i)
        {
            if(freqMap.count(nums[i]) == 0)
            {
                if(s < k)
                {
                    sortedV[s++] = nums[i];
                    freqMap[nums[i]] = {s-1, 1};
                }
                else
                {
                    freqMap[nums[i]] = {-1, 1};
                }
            }
            else
            {
                freqMap[nums[i]][1]++;
                if(freqMap[nums[i]][0] == -1)
                {
                    if(freqMap[nums[i]][1] > freqMap[sortedV[s-1]][1])
                    {
                        freqMap[sortedV[s-1]][0] = -1;
                        freqMap[nums[i]][0] = s-1;
                        sortedV[s-1] = nums[i];
                    }
                }
                for(j=freqMap[nums[i]][0]-1;j>=0;j--)
                {
                    if(freqMap[nums[i]][1] < freqMap[sortedV[j]][1])
                        break;
                    else
                    {
                        freqMap[sortedV[j]][0]++;
                        freqMap[nums[i]][0]--;
                        temp = sortedV[j];
                        sortedV[j] = sortedV[j+1];
                        sortedV[j+1] = temp;
                    }
                }
            }
        }
        return sortedV;
    }
};