class Solution {
private:
    int mergeSort(vector<int>& prices, int start, int end)
    {
        static int buffer[100100];
        int b = 0;
        if(start >= end)
            return 0;
        int i = start, mid = (start + end) / 2;
        int j = mid + 1;
        int c1 = mergeSort(prices, start, mid);
        int c2 = mergeSort(prices, mid + 1, end);
        int count = c1 > c2 ? c1 : c2;
        count = prices[end] - prices[start] > count ? prices[end] - prices[start] : count;
        while(i <= mid && j <= end)
        {
            if(prices[i] < prices[j])
            {
                buffer[b++] = prices[i];
                i++;
            }
            else
            {
                buffer[b++] = prices[j];
                j++;
            }
        }
        while(i <= mid)
        {
            buffer[b++] = prices[i];
            i++;
        }
        while(j <= end)
        {
            buffer[b++] = prices[j];
            j++;
        }
        for(int i=0;i<end-start+1;i++)
            prices[i+start] = buffer[i];
        return count;
    }
public:
    int maxProfit(vector<int>& prices) {
        return mergeSort(prices, 0, prices.size()-1);
    }
};