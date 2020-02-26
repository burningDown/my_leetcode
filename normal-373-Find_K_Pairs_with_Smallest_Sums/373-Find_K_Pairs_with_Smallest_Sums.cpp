class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int &l1 = nums1.size();
        const int &l2 = nums2.size();

        list<vector<int>> sortedQueue;
        list<vector<int>>::iterator it;
        bool flag = false;
        vector<vector<int>> result;

        if(l1 == 0 || l2 == 0)
            return result;

        sortedQueue.push_back({0, 0});
        for(int i=0;i<k && !sortedQueue.empty();i++)
        {
            const list<vector<int>>::iterator &begin = sortedQueue.begin();
            it = begin;
            result.push_back({nums1[(*it)[0]], nums2[(*it)[1]]});

            if((*it)[0]+1 < l1)
            {
                flag = false;
                for(it = begin;it!=sortedQueue.end();it++)
                {
                    if(nums1[(*begin)[0]+1] + nums2[(*begin)[1]] < nums1[(*it)[0]] + nums2[(*it)[1]])
                        break;
                    else if((*begin)[0]+1 == (*it)[0] && (*begin)[1] == (*it)[1])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    sortedQueue.insert(it, {(*begin)[0]+1, (*begin)[1]});
            }

            it = sortedQueue.begin();
            if((*it)[1]+1 < l2)
            {
                flag = false;
                for(it = begin;it!=sortedQueue.end();it++)
                {
                    if(nums1[(*begin)[0]] + nums2[(*begin)[1]+1] < nums1[(*it)[0]] + nums2[(*it)[1]])
                        break;
                    else if((*begin)[0] == (*it)[0] && (*begin)[1]+1 == (*it)[1])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    sortedQueue.insert(it, {(*begin)[0], (*begin)[1]+1});
            }

            sortedQueue.pop_front();
        }
        return result;
    }
};