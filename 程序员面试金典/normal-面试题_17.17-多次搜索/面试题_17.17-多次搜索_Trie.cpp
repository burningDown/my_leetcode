struct TrieNode
{
    int wordIdx;
    unordered_map<char, TrieNode*> children;
    TrieNode():wordIdx(-1){}
};
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        TrieNode *root = new TrieNode();
        TrieNode *node;
        const int sl = smalls.size();
        const int bl = big.size();
        vector<vector<int>> result(sl, vector<int>());

        for(int i=0;i<sl;i++)
        {
            string &s = smalls[i];
            node = root;
            for(char &c : s)
            {
                if(node->children.count(c) == 0)
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->wordIdx = i;
        }

        for(int i=0;i<bl;i++)
        {
            node = root;
            for(int j=i;j<bl;j++)
            {
                if(node->children.count(big[j]) > 0)
                {
                    node = node->children[big[j]];
                    if(node->wordIdx >= 0)
                        result[node->wordIdx].push_back(i);
                }
                else
                    break;
            }
        }
        return result;
    }
};