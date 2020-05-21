class Solution {
public:
    string longestPalindrome(string s) {
        const int l = s.size();

        int start = 0, end = 0;

        for(int i=0;i<l;i++)
        {
            for(int j=i-1;j>=0&&2*i-j<l;j--)
            {
                if(s[j] == s[2*i-j])
                {
                    if(2 * (i - j) > end - start)
                    {
                        start = j;
                        end = 2*i-j;
                    }
                }
                else
                    break;
            }
            for(int j=i;j>=0&&2*i-j+1<l;j--)
            {
                if(s[j] == s[2*i-j+1])
                {
                    if(2 * (i - j) + 1 > end - start)
                    {
                        start = j;
                        end = 2*i-j+1;
                    }
                }
                else
                    break;
            }
        }

        return s.substr(start, end-start+1);
    }
};