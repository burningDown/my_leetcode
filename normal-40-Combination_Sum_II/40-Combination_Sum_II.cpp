class Solution {
private:
    vector<int> buffer;
    vector<vector<int>> result;
    int l;
    int target;

    void backtrack(vector<int> &candidates, int now, int sum)
    {
        buffer.push_back(candidates[now]);
        int pre = -1;

        if(sum + candidates[now] == target)
        {
            result.push_back(buffer);
        }
        else if(sum + candidates[now] < target)
        {
            for(int i=now+1;i<l;i++)
            {
                if(pre != candidates[i])
                {
                    pre = candidates[i];
                    backtrack(candidates, i, sum+candidates[now]);
                }
            }
        }
        buffer.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        l = candidates.size();
        int pre = -1;
        buffer.reserve(l+1);
        this->target = target;

        for(int i=0;i<l;i++)
        {
            if(pre != candidates[i])
            {
                pre = candidates[i];
                backtrack(candidates, i, 0);
            }
        }
        return result;
    }
};