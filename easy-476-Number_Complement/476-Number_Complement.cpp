class Solution {
public:
    int findComplement(int num) {
        return int(long(~num) + long(1 << int(log2(num))+1));
    }
};