class Solution {
public:
    int minSwaps(vector<int>& data) {
        int total = 0, i, maxOnes = 0, countOnes = 0;
        const int l = data.size();
        for(i=0;i<l;i++)
            total += data[i];
        for(i=0;i<total;i++)
            countOnes += data[i];
        maxOnes = countOnes;
        for(i=1;i<=l-total;i++)
        {
            countOnes -= data[i-1];
            countOnes += data[i+total-1];
            if(countOnes > maxOnes)
                maxOnes = countOnes;
        }
        return total - maxOnes;
    }
};