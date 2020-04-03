class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i : prices)
        {
            profit = i - minPrice > profit ? i - minPrice : profit;
            minPrice = i < minPrice ? i : minPrice;
        }
        return profit;
    }
};