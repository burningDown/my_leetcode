class Solution {
public:
    int add(int a, int b) {
        while(b=(unsigned int)(b&~(a^=b))<<1);
        return a;
    }
};
/*
The mentioned solution is equivalent to the following:

class Solution {
public:
	int add(int a, int b) {
		int sum, carry;
		while(b)
		{
			sum = a ^ b;
			carry = (a & b) << 1;
			a = sum;
			b = carry;
		}
		return a;
	}
}
*/