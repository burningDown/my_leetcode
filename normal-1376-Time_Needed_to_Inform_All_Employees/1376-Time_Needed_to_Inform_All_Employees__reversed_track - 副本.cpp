class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = -1;
        int currentTime;
        int idx;

        for(int i=0;i<n;i++)
        {
            idx = i;
            currentTime = 0;
            while(idx != -1)
            {
                currentTime += informTime[idx];
                maxTime = max(maxTime, currentTime);
                idx = manager[idx];
            }
        }
        
        return maxTime;
    }
};