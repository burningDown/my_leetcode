class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        const int l1 = s1.size();
        const int l2 = s2.size();
        int count1 = 0, count2 = 0;
        int i = 0, j = 0;
        int recurStart = 0, recurEnd = 0;
        int s2Start = 0, s2End = 0;

        int bitMap = 0;
        string shrinkedS1;
        vector<vector<int>> shrinkedS1Count;

        for(i=0;i<l2;i++)
        {
            bitMap |= (1 << s2[i]-'a');
        }
        shrinkedS1.reserve(l1);
        for(i=0;i<l1;i++)
        {
            if(bitMap & (1 << s1[i] - 'a'))
            {
                shrinkedS1.push_back(s1[i]);
            }
        }

        const int sl1 = shrinkedS1.size();
        shrinkedS1Count.resize(sl1, {-1, -1});
        
        i = j = 0;
        while(count1 < n1)
        {
            if(s2[i] == shrinkedS1[j])
            {
                i++;
                if(i >= l2)
                {
                    i = 0;
                    count2++;
                    if(shrinkedS1Count[j][0] >= 0)
                    {
                        recurStart = shrinkedS1Count[j][0];
                        recurEnd = count1;
                        s2Start = shrinkedS1Count[j][1];
                        s2End = count2;
                        break;
                    }
                    else
                    {
                        shrinkedS1Count[j][0] = count1;
                        shrinkedS1Count[j][1] = count2;
                    }
                }
            }
            j++;
            if(j >= sl1)
            {
                j = 0;
                count1++;
            }
        }

        if(recurEnd - recurStart != 0)
        {
            count2 += (s2End - s2Start) * ((n1 - count1 - 1) / (recurEnd - recurStart));
            count1 += (recurEnd - recurStart) * ((n1 - count1 - 1) / (recurEnd - recurStart));
        }
        
        j++;
        if(j >= sl1)
        {
            j = 0;
            count1++;
        }
        while(count1 < n1)
        {
            if(s2[i] == shrinkedS1[j])
            {
                i++;
                if(i >= l2)
                {
                    i = 0;
                    count2++;
                }
            }
            j++;
            if(j >= sl1)
            {
                j = 0;
                count1++;
            }
        }

        return count2 / n2;
    }
};