class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int targetMap[1005] = { 0 };
        const int l = target.size();

        if(l != arr.size())
            return false;
        
        for(int i=0;i<l;i++)
            targetMap[target[i]]++;
        
        for(int i=0;i<l;i++)
        {
            if(targetMap[arr[i]] == 0)
                return false;
            targetMap[arr[i]]--;
        }
        return true;
    }
};