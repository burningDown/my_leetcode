class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int p1=1, p2=2;
        vector<vector<int>> result;
        result.reserve(1000);
        while(p2 > p1)
        {
            if((p2-p1+1)*(p1+p2)/2 == target)
            {
                vector<int> node;
                node.reserve(p2-p1+10);
                for(int i=p1;i<=p2;i++)
                    node.push_back(i);
                result.push_back(node);
                p2++;
            }
            else if((p2-p1+1)*(p1+p2)/2 < target)
                p2++;
            else
                p1++;
        }
        return result;
    }
};