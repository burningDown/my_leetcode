class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int a;
        vector<vector<int>> result;
        result.reserve(1000);
        for(int n=(1+sqrt(1+8*target))/2;n > 1;n--)
        {
            if((2*target - n*(n-1))!=0 && (2*target - n*(n-1))%(2*n) == 0)
            {
                vector<int> node;
                node.reserve(n);
                a = (2*target - n*(n-1))/(2*n);
                for(int i=0;i<n;i++)
                    node.push_back(a+i);
                result.push_back(node);
            }
        }
        return result;
    }
};