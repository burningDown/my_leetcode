class Solution {
public:
    int trap(vector<int>& height) {
        const int l = height.size();
        int count = 0;
        int left = 0;
        bool isPool = false;
        int max = 0;
        for(int i=0;i<l;i++)
        {
            if(height[i] > max)
                max = height[i];
        }
        for(int i=0;i<=max;i++)
        {
            left = 0;
            isPool = false;
            for(int j=0;j<l;j++)
            {
                if(!isPool)
                {
                    if(j > 0 && height[j] <= i && height[j-1] > i)
                    {
                        isPool = true;
                        left = j;
                    }
                }
                else
                {
                    if(height[j] > i)
                    {
                        isPool = false;
                        count += j - left;
                    }
                }
            }
        }
        return count;
    }
};