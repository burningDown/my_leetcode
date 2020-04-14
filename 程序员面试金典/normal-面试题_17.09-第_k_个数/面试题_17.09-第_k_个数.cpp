
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> numArray;
        int p[3] = { 0 }, minIdx, minValue;
        int i;

        numArray.reserve(k + 10);
        numArray.push_back(1);

        i=1;
        while(i<k)
        {
            if(numArray[p[0]] * 3 < numArray[p[1]] * 5)
            {
                minIdx = 0;
                minValue = numArray[p[0]] * 3;
            }
            else
            {
                minIdx = 1;
                minValue = numArray[p[1]] * 5;
            }
            
            if(numArray[p[2]] * 7 < minValue)
            {
                minIdx = 2;
                minValue = numArray[p[2]] * 7;
            }
            
            if(*(numArray.end()-1) != minValue)
            {
                numArray.push_back(minValue);
                i++;
            }
            p[minIdx]++;
        }
        return *(numArray.end()-1);
    }
};