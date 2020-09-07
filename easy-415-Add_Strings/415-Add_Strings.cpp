class Solution {
public:
    string addStrings(string num1, string num2) {
        const int l1 = num1.size();
        const int l2 = num2.size();
        const int ml = min(l1, l2);
        int carry = 0;
        int b;
        string reversedRes;

        reversedRes.reserve(max(l1, l2) + 1);
        for(int i=0;i<ml;i++)
        {
            b = num1[l1 - i - 1] - '0' + num2[l2 - i -1] - '0' + carry;
            carry = b / 10;
            b = b % 10;
            reversedRes += b + '0';
        }
        for(int i=ml;i<l1;i++)
        {
            b = num1[l1 - i - 1] - '0' + carry;
            carry = b / 10;
            b = b % 10;
            reversedRes += b + '0';
        }
        for(int i=ml;i<l2;i++)
        {
            b = num2[l2 - i - 1] - '0' + carry;
            carry = b / 10;
            b = b % 10;
            reversedRes += b + '0';
        }
        if(carry > 0)
            reversedRes += carry + '0';
        reverse(reversedRes.begin(), reversedRes.end());
        return reversedRes;
    }
};