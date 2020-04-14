const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                       "Nine", "Ten", "Eleven","Twelve", "Thirteen", "Fourteen", "Fifteen",
                       "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string gens[] = {"Hundred", "Thousand", "Million", "Billion"};

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        int digits = int(log10(num));
        int base = (int)pow(10, digits);
        int bit, teen;
        bool hasDigit = false;
        string result;
        result.reserve(120);
        while(digits >= 0)
        {
            if(digits % 3 == 2)
            {
                bit = (num / base) % 10;
                if(bit > 0)
                {
                    result += ones[bit];
                    result += ' ';
                    result += gens[0];
                    result += ' ';

                    hasDigit = true;
                }
            }
            else if(digits % 3 == 1)
            {
                bit = (num / base) % 10;
                if(bit == 1)
                {
                    teen = (num / (base / 10)) % 100;
                    result += ones[teen];
                    result += ' ';

                    num %= base;
                    digits--;
                    base /= 10;

                    hasDigit = true;
                }
                else if(bit > 1)
                {
                    result += tens[bit];
                    result += ' ';

                    hasDigit = true;
                }
            }
            else
            {
                bit = (num / base) % 10;
                if(bit > 0)
                {
                    result += ones[bit];
                    result += ' ';

                    hasDigit = true;
                }
            }

            if(hasDigit && digits % 3 == 0)
            {
                if(digits / 3 > 0)
                {
                    result += gens[digits / 3];
                    result += ' ';

                    hasDigit = false;
                }
            }

            num %= base;
            digits--;
            base /= 10;
        }
        result.pop_back();
        return result;
    }
};