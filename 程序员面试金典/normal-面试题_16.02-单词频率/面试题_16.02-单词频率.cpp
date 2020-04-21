struct TrieNode
{
    int freq;
    unordered_map<char, TrieNode*> children;
    TrieNode() :freq(0){}
};

class WordsFrequency {
private:
    TrieNode *root;
public:
    WordsFrequency(vector<string>& book) {
        TrieNode *node;
        root = new TrieNode();

        for(string &s : book)
        {
            node = root;
            for(char &c : s)
            {
                if(node->children.count(c) == 0)
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->freq++;
        }
    }
    
    int get(string word) {
        TrieNode *node = root;
        for(char &c : word)
        {
            if(node->children.count(c) > 0)
                node = node->children[c];
            else
                return 0;
        }
        return node->freq;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */