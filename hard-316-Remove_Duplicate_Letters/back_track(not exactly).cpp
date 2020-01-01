class Solution {
private:
    int countMap[26];
    char resultV[1000];
    //int cCurrent;
    //int cNext;
    int borderFlag;
    char flagChar;
    int l;

    void back_track(string &s)
    {
    	if(borderFlag >= l)
    		return;
    	int idx = borderFlag;
        char cCurrent = s[idx];

        if(countMap[cCurrent-'a'] == 0)
        {
            borderFlag++;
            back_track(s);
        }
        else if(countMap[cCurrent-'a'] == 1)
        {
            countMap[cCurrent-'a']--;
            flagChar = resultV[idx] = cCurrent;
        }
        else
        {
            borderFlag++;
            countMap[cCurrent-'a']--;
            back_track(s);
            if(cCurrent < flagChar)
            {
                countMap[cCurrent-'a'] = 0;
                flagChar = resultV[borderFlag] = cCurrent;
            }
        }
    }
public:
    Solution(): countMap({0}), resultV({0}), borderFlag(0){}
    string removeDuplicateLetters(string s) {
        int i;
        l = s.size();
        for(i=0;i<l;i++)
            countMap[s[i]-'a']++;
        for(borderFlag=0;borderFlag<l;borderFlag++)
        {
            back_track(s);
        }

        string result;
        for(i=0;i<l;i++)
            if(resultV[i]>0)
                result += resultV[i];
        return result;
    }
};