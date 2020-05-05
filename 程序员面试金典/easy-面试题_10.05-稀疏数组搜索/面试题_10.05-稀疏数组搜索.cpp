class Solution {
private:
    int binarySearch(vector<string> &words, string &s, int i, int j)
    {
        if(i >= j)
        {
            if(words[i] == s)
                return i;
            else
                return -1;
        }
        int mid = (i + j) / 2;
        int idx;
        if(words[mid] == s)
            return mid;
        else if(words[mid] == "")
        {
            if((idx=binarySearch(words, s, i, mid)) >= 0)
                return idx;
            if((idx=binarySearch(words, s, mid+1, j)) >= 0)
                return idx;
        }
        else if(words[mid] < s)
        {
            if((idx=binarySearch(words, s, mid+1, j)) >= 0)
                return idx;
        }
        else
        {
            if((idx=binarySearch(words, s, i, mid)) >= 0)
                return idx;
        }
        return -1;
    }
public:
    int findString(vector<string>& words, string s) {
        return binarySearch(words, s, 0, words.size()-1);
    }
};