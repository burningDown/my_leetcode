class Solution {
public:
    int multiply(int A, int B) {
        int accu = 0;
        while(B)
        {
            // accu += A * (B & 1);
            if(B - ((B >> 1) << 1))
                accu += A;
            B >>= 1;
            A <<= 1;
        }
        return accu;
    }
};