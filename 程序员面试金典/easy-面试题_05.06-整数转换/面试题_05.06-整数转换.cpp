class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int x = A ^ B;
        int count = 0;
        while(x != 0)
        {
            count++;
            x = x&(x-1);
        }
        return count;
    }
};