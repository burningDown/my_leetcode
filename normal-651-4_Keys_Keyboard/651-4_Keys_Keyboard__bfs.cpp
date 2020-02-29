class Solution {
public:
    int maxA(int N) {
        queue<vector<int>> stateQueue;  // key, buffer, length, step
        vector<int> it;
        int maxLength = 0;

        stateQueue.push({0, 0, 0, 0});
        while(!stateQueue.empty())
        {
            it = stateQueue.front();
            stateQueue.pop();
            
            //printf("step: %d, length: %d, buffer: %d, key: %d\n", it[3], it[2], it[1], it[0]);

            if(it[2] > maxLength)
                maxLength = it[2];

            if(it[0] == 1)
            {
                if(it[3] + 1 <= N)   //  Key 1
                {
                    stateQueue.push({1, it[1], it[2]+1, it[3]+1});
                }
                if(it[3] + 3 <= N)   // Key 2,3,4
                {
                    stateQueue.push({4, it[2], it[2]+it[2], it[3]+3});
                }
            }

            else if(it[0] == 4)
            {
                if(it[3] + 1 <= N)   // Key 4
                {
                    stateQueue.push({4, it[1], it[2]+it[1], it[3]+1});
                }
                if(it[3] + 3 <= N)   // Key 2,3,4
                {
                    stateQueue.push({4, it[2], it[2]+it[2], it[3]+3});
                }
            }
            else
            {
                if(it[3] + 1 <= N)   //  Key 1
                {
                    stateQueue.push({1, it[1], it[2]+1, it[3]+1});
                }
            }
        }

        return maxLength;
    }
};