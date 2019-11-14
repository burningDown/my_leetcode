class Solution {
private:
    int majorBag[3];
    int majorCount[3];
public:
    Solution():majorBag({-9999,-9999,-9999}), majorCount({0,0,0}){}
    vector<int> majorityElement(vector<int>& nums) {
        int l = nums.size();
        int i;
        vector<int> result;
        for(i=0;i<l;i++)
        {
            int num = nums[i];
            int j;
            for(j=0;j<3;j++)
            {
                if(majorBag[j] == num)
                {
                    majorCount[j]+=2;
                    break;
                }
                else if(majorBag[j] == -9999)
                {
                    majorBag[j] = num;
                    majorCount[j] = 2;
                    break;
                }
            }
            if(j == 3)
            {
                for(j=0;j<3;j++)
                {
                    if(--majorCount[j] == 0)
                    {
                        majorBag[j] = num;
                        majorCount[j] = 2;
                        break;
                    }
                }
            }
        }
        majorCount[0] = majorCount[1] = majorCount[2] = 0;
        int flag = l/3;
        for(i=0;i<l;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(majorBag[j] == nums[i])
                {
                    majorCount[j]++;
                }
            }
        }
        for(i=0;i<3;i++)
        {
            if(majorCount[i] > flag)
                result.push_back(majorBag[i]);
        }
        return result;
    }
};