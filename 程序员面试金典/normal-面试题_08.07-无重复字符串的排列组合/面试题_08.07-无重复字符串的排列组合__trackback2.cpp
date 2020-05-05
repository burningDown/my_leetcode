inline void swap(char &c1, char &c2)
{
    char c0 = c1;
    c1 = c2;
    c2 = c0;
}

class Solution {
private:
    void trackback(vector<string> &result, string &S, int i)
    {
        if(i >= S.size()-1)
        {
            result.push_back(S);
            return;
        }

        const int l = S.size();

        trackback(result, S, i+1);
        for(int left = i+1;left<l;left++)
        {
            swap(S[i], S[left]);
            trackback(result, S, i+1);
            swap(S[i], S[left]);
        }
    }
public:
    vector<string> permutation(string S) {
        vector<string> result;

        trackback(result, S, 0);

        return result;
    }
};