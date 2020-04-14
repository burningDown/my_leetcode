class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int a = (long(1) << 32) - 1;
        vector<int> result(length, 0);
        int start = y * w / 32 + x1 / 32;
        int end = y * w / 32 + x2 / 32;

        int startPixel = (long(1) << 32 - x1 % 32) - 1;
        int endPixel = (~((long(1) << 32 - x2 % 32) - 1)) >> 1;

        if(start < end)
        {
            result[start] = startPixel;
            for(int i=start+1;i<end;i++)
                result[i] = -1;
            result[end] = endPixel;
        }
        else
        {
            result[start] = startPixel;
            result[end] &= endPixel;
        }

        return result;
    }
};