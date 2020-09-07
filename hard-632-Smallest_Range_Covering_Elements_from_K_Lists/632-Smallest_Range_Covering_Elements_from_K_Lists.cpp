struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> orderedQueue;
        queue<pair<int, int>> cacheQueue;
        const int k = nums.size();
        vector<int> idxMap(k, 0);
        int count = 0;
        int clr = 0, crr = 0;
        pair<int, int> lr(0, 0), rr(INT_MAX, 0);
        pair<int, int> value;

        for(int i=0;i<k;i++)
        {
            int lk = nums[i].size();
            for(int j=0;j<lk;j++)
            {
                orderedQueue.push({nums[i][j], i});
            }
        }

        while(!orderedQueue.empty())
        {
            value = orderedQueue.top();
            orderedQueue.pop();

            if(idxMap[value.second] == 0)
                count++;
            idxMap[value.second]++;
            cacheQueue.push(value);
            while(count == k)
            {
                pair<int, int> front = cacheQueue.front();
                if(value.first - front.first < rr.first - lr.first)
                {
                    lr = front;
                    rr = value;
                }
                idxMap[front.second]--;
                if(idxMap[front.second] == 0)
                    count--;
                cacheQueue.pop();
            }
        }

        return {lr.first, rr.first};
    }
};