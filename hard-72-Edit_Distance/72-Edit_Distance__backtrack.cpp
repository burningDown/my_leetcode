inline int min(int a, int b)
{
    return a < b ? a : b;
}
class Solution {
private:
    int backtrack(string &word1, string &word2, int i, int j)
    {
        if(j == word2.size())
            return word1.size() - i;
        if(i == word1.size())
            return word2.size() - j;

        int minStep = min(backtrack(word1, word2, i + 1, j), backtrack(word1, word2, i, j + 1)) + 1;
        
        if(word1[i] == word2[j])
            minStep = min(backtrack(word1, word2, i + 1, j + 1), minStep);
        else
            minStep = min(backtrack(word1, word2, i + 1, j + 1) + 1, minStep);
        return minStep;
    }
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0 || word2.size() == 0)
            return word1.size() == 0 ? word2.size() : word1.size();

        return backtrack(word1, word2, 0, 0);
    }
};