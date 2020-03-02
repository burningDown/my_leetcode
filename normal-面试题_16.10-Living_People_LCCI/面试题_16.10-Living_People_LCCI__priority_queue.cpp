vector<int> *pBirth;
bool cmp(int i, int j)
{
    return (*pBirth)[i] < (*pBirth)[j];
}

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        const int l = birth.size();
        vector<int> idxOfOrder(l);
        priority_queue<int, vector<int>, greater<int>> deathQueueInOrder;
        int max = 0, maxYear;

        for(int i=0;i<l;i++)
            idxOfOrder[i] = i;

        pBirth = &birth;

        sort(idxOfOrder.begin(), idxOfOrder.end(), cmp);

        for(int i=0;i<l;i++)
        {
            deathQueueInOrder.push(death[idxOfOrder[i]]);

            while(deathQueueInOrder.top() < birth[idxOfOrder[i]])
                deathQueueInOrder.pop();
            
            if(deathQueueInOrder.size() > max)
            {
                max = deathQueueInOrder.size();
                maxYear = birth[idxOfOrder[i]];
            }
        }

        return maxYear;
    }
};