struct TrieNode
{
    bool isWord;
    int maxDepth;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord(false), maxDepth(0) {}
};

class Solution {
private:
    void backtrack(TrieNode *root, vector<TrieNode*> &nodes, vector<string> &words, vector<string> &result, vector<string> &tempResult)
    {
        bool flag = false;
        for(TrieNode *node : nodes)
        {
            flag = true;
            if(!node->isWord)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            if(result.size() == 0 || result.size() * result[0].size() < tempResult.size() * tempResult[0].size())
                result = tempResult;
        }

        vector<TrieNode*> tempNodes = nodes;
        
        for(string &s : words)
        {
            if(tempResult.size() == 0)
            {
                nodes.resize(s.size(), root);
                tempNodes = nodes;
            }
            if(tempResult.size() == 0 || tempResult[0].size() == s.size())
            {
                const int l = s.size();
                flag = true;
                for(int i=0;i<l;i++)
                {
                    char &c = s[i];
                    if(nodes[i]->children.count(c) == 0 || result.size() > 0 && nodes[i]->children[c]->maxDepth * l <= result.size() * result[0].size())
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        nodes[i] = nodes[i]->children[c];
                    }
                }
                if(flag)
                {
                    tempResult.push_back(s);

                    backtrack(root, nodes, words, result, tempResult);

                    tempResult.pop_back();
                }
                nodes = tempNodes;
            }
        }
    }
public:
    vector<string> maxRectangle(vector<string>& words) {
        TrieNode *root = new TrieNode();
        TrieNode *node;
        vector<string> result, tempResult;
        vector<TrieNode*> nodes;
        for(string &s : words)
        {
            node = root;
            for(char &c : s)
            {
                if(node->children.count(c) == 0)
                    node->children[c] = new TrieNode();
                node = node->children[c];
                if(node->maxDepth < s.size())
                    node->maxDepth = s.size();
            }
            node->isWord = true;
        }

        backtrack(root, nodes, words, result, tempResult);
        return result;
    }
};