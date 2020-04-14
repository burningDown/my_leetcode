struct TrieNode
{
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord(false) {}
};
bool cmp(string &s1, string &s2)
{
    return s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2;
}
class Solution {
private:
    void constructTrie(TrieNode *root, string &word)
    {
        TrieNode *node = root;
        for(char c : word)
        {
            if(node->children.count(c) == 0)
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isWord = true;
    }
    bool judge(TrieNode *root, string &word, int start)
    {
        TrieNode *node = root;
        const int l = word.size();
        for(int i=start;i<l-1;i++)
        {
            if(node->children.count(word[i]) == 0)
                return false;
            node = node->children[word[i]];
            if(node->isWord)
            {
                if(judge(root, word, i+1))
                    return true;
            }
        }
        
        if(node->children.count(word[l-1]) == 0)
            return false;
        node = node->children[word[l-1]];
        if(node->isWord)
        {
            if(start > 0)
                return true;
        }
        return false;
    }
public:
    string longestWord(vector<string>& words) {
        if(words.size() == 1)
            return "";
        TrieNode *root = new TrieNode();
        const int l = words.size();
        int i, j;

        sort(words.begin(), words.end(), cmp);

        for(int i=0;i<l;i++)
            constructTrie(root, words[i]);

        i = l-1;
        while(i >= 0)
        {
            j = i;
            while(i > 0 && words[i].size() == words[i-1].size())
            {
                i--;
            }
            for(int k=i;k<=j;k++)
            {
                if(judge(root, words[k], 0))
                    return words[k];
            }
            i--;
            j = i;
        }
        return "";
    }
};