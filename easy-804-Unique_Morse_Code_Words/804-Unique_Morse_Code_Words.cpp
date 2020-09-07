struct BinaryTrieNode
{
    bool isEnd;
    BinaryTrieNode *dot;
    BinaryTrieNode *dash;
    BinaryTrieNode(): isEnd(false), dot(NULL), dash(NULL) {}
};

const vector<string> morseMap = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        BinaryTrieNode *root = new BinaryTrieNode();
        BinaryTrieNode *node;
        int res = 0;
        for(string &word : words)
        {
            node = root;
            for(char &rawC : word)
            {
                for(char c : morseMap[rawC - 'a'])
                {
                    if(c == '.')
                    {
                        if(node->dot == NULL)
                            node->dot = new BinaryTrieNode();
                        node = node->dot;
                    }
                    else if(c == '-')
                    {
                        if(node->dash == NULL)
                            node->dash = new BinaryTrieNode();
                        node = node->dash;
                    }
                }
            }
            if(!node->isEnd)
            {
                node->isEnd = true;
                res++;
            }
        }
        return res;
    }
};