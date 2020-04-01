class Solution {
public:
    int minArray(vector<int>& numbers) {
        int min = INT_MAX;
        for(int i : numbers)
        {
            if(min > i)
                min = i;
        }
        return min;
    }
};