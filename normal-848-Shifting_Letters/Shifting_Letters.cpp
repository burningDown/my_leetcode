class Solution
{
public:
    string shiftingLetters(string S, vector<int>& shifts)
    {
        int shi = 0;
        for(int i=shifts.size()-1;i>=0;i--)
        {
            shi = (shi + shifts[i]) % 26;
            S[i] = (S[i] - 'a' + shi) % 26 + 'a';
        }
        return S;
    }
};