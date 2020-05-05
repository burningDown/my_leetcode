struct TrieNode
{
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord(false){}
};

class Solution {
private:
    vector<string> split(string &sentence)
    {
        string buffer;
        vector<string> result;
        for(char &c : sentence)
        {
            if(c == ' ')
            {
                result.push_back(buffer);
                buffer.clear();
            }
            else
            {
                buffer += c;
            }
        }
        if(buffer.size() > 0)
            result.push_back(buffer);
        return result;
    }
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode *root = new TrieNode();
        TrieNode *node;
        string result;
        string buffer;
        const int l = sentence.size();
        for(string &s : dict)
        {
            node = root;
            for(char &c : s)
            {
                if(node->children.count(c) == 0)
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->isWord = true;
        }
        
        vector<string> splited = split(sentence);
        for(string &s : splited)
        {
            node = root;
            buffer.clear();
            for(char &c : s)
            {
                if(node->children.count(c) == 0)
                {
                    buffer = s;
                    break;
                }
                else
                {
                    buffer += c;
                    node = node->children[c];
                    if(node->isWord)
                    {
                        break;
                    }
                }
            }
            result += buffer;
            result += ' ';
        }
        result.pop_back();
        return result;
    }
};