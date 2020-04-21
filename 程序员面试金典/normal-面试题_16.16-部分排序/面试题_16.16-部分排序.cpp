class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        const int l = array.size();
        if(l <= 1)
            return {-1, -1};

        int minIdx = -1;
        int maxIdx = -1;

        for(int i=1;i<l;i++)
        {
            if(minIdx < 0)
            {
                if(array[i] < array[i-1])
                {
                    minIdx = i;
                }
            }
            else
            {
                if(array[i] < array[minIdx])
                {
                    minIdx = i;
                }
            }
        }

        for(int i=l-1;i>0;i--)
        {
            if(maxIdx < 0)
            {
                if(array[i] < array[i-1])
                {
                    maxIdx = i-1;
                }
            }
            else
            {
                if(array[i-1] > array[maxIdx])
                {
                    maxIdx = i-1;
                }
            }
        }

        if(minIdx < 0 || maxIdx < 0)
            return {-1, -1};

        for(int i=0;i<l;i++)
        {
            if(array[minIdx] < array[i])
            {
                minIdx = i;
                break;
            }
        }

        for(int i=l-1;i>=0;i--)
        {
            if(array[maxIdx] > array[i])
            {
                maxIdx = i;
                break;
            }
        }
        return {minIdx, maxIdx};
    }
};