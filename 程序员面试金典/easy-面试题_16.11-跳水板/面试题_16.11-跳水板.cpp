class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0)
            return {};
        
        vector<int> result;
        result.reserve(k + 2);
        result.push_back(shorter * k);

        if(longer == shorter)
            return result;
        
        for(int i=0;i<k;i++)
            result.push_back(result.back() + longer - shorter);
        return result;
    }
};