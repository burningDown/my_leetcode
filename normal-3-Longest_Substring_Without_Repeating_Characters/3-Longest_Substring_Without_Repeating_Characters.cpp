class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1 = 0, p2 = 1;
        int binaryMap[4] = { 0 };
        const int l = s.size();

        if(l == 0)
            return 0;
    
        int maxLength = 1, currentLength = 1;

        binaryMap[s[0] / 32] |= 1 << s[0] % 32;
        while(p2 < l)
        {
            if(!(binaryMap[s[p2] / 32] & 1 << s[p2] % 32))
            {
                binaryMap[s[p2] / 32] |= 1 << s[p2] % 32;
                ++p2;
                
                currentLength = p2 - p1;
                maxLength = max(maxLength, currentLength);
            }
            else
            {
                binaryMap[s[p1] / 32] &= ~(1 << s[p1] % 32);

                ++p1;
            }
        }
        return maxLength;
    }
};