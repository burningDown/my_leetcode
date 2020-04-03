class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int pokerMap[15] = { 0 };
        for(int i : nums)
        {
            if(pokerMap[i] > 0 && i != 0)
                return false;
            pokerMap[i]++;
        }
        int i;
        for(i=1;i<15;i++)
            if(pokerMap[i] > 0)
                break;
        int count = nums.size();
        for(;i<15;i++)
        {
            if(pokerMap[i] == 1)
            {
                count--;
                if(count <= 0)
                    return true;
            }
            else
            {
                pokerMap[0]--;
                if(pokerMap[0] < 0)
                    return false;
                count--;
                if(count <= 0)
                    return true;
            }
        }
        return true;
    }
};