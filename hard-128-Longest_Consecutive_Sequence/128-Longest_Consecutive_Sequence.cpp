class DSU
{
private:
    unordered_map<int, int> dsuMap;
    unordered_map<int, int> numsMap;

    int maxContinuous;
public:
    DSU(): maxContinuous(0) {}
    int find(int num)
    {
        int temp;
        for(temp = num;dsuMap.find(temp)!=dsuMap.end();temp=dsuMap[temp]);
        return temp;
    }
    void insert(int num)
    {
        if(numsMap.find(num) == numsMap.end())
        {
            numsMap[num] = 1;
            
            maxContinuous = max(maxContinuous, numsMap[num]);
            if(numsMap.find(num + 1) != numsMap.end())
            {
                dsuMap[num + 1] = num;
                numsMap[num] += numsMap[num + 1];

                maxContinuous = max(maxContinuous, numsMap[num]);
            }
            if(numsMap.find(num - 1) != numsMap.end())
            {
                int key = find(num - 1);
                dsuMap[num] = key;
                numsMap[key] += numsMap[num];

                maxContinuous = max(maxContinuous, numsMap[key]);
            }
        }
    }
    int getMax()
    {
        return maxContinuous;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;
        for(int &i : nums)
            dsu.insert(i);
        
        return dsu.getMax();
    }
};