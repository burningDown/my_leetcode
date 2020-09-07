struct TrieNode
{
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord(false) {}
};

class Solution {
private:
    bool backtrack(string &s, int si, TrieNode *root)
    {
        if(si >= s.size())
            return true;
        
        TrieNode *node = root;
        for(int i=si;i<s.size();i++)
        {
            if(node->children.find(s[i]) == node->children.end())
                return false;
            if(node->children[s[i]]->isWord)
            {
                if(backtrack(s, i+1, root))
                    return true;
            }
            node = node->children[s[i]];
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode root;
        for(string &word : wordDict)
        {
            TrieNode *node = &root;
            for(char &c : word)
            {
                if(node->children.find(c) == node->children.end())
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->isWord = true;
        }

        return backtrack(s, 0, &root);
    }
};