class Solution {
public:
    string printBin(double num) {
        if(num < 0.)
            return "ERROR";
        string result("0.");
        int count = 1;

        result.reserve(40);
        while(num > 0.)
        {
            num *= 2;
            if(num >= 1.)
            {
                num -= 1;
                result += '1';
            }
            else
            {
                result += '0';
            }
            count++;
            if(count > 32)
                return "ERROR";
        }
        return result;
    }
};