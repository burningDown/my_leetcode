class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1 == 0 || n2 == 0)
            return 0;
        int count1 = 0, count2 = 0;
        const int l1 = s1.size();
        const int l2 = s2.size();
        int i = 0, j = 0;
        string shrinkedS2;

        int bitMap = 0;

        for(int i=0;i<l1;i++)
            bitMap |= 1 << s1[i]-'a';
        shrinkedS2.reserve(l1);
        for(int i=0;i<l2;i++)
        {
            if(bitMap&(1<<s2[i]-'a'))
                shrinkedS2.push_back(s2[i]);
        }

        const int sl2 = shrinkedS2.size();

        while(count1 < n1)
        {
            if(i == 0 && j == 0 && count1 > 1 && count2 > 1)
                break;
            if(shrinkedS2[i] == s1[j])
            {
                i++;
                if(i >= sl2)
                {
                    count2++;
                    i = 0;
                }
            }
            j++;
            if(j >= l1)
            {
                count1++;
                j = 0;
            }
        }

        count2 *= n1 / count1;
        count1 *= n1 / count1;
        while(count1 < n1)
        {
            if(shrinkedS2[i] == s1[j])
            {
                i++;
                if(i >= sl2)
                {
                    count2++;
                    i = 0;
                }
            }
            j++;
            if(j >= l1)
            {
                count1++;
                j = 0;
            }
        }


        return count2 / n2;
    }
};