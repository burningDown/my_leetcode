struct TrieNode
{
    int wordIdx;
    list<int> wordsIdxList;
    TrieNode* children[26];
    TrieNode(): wordIdx(-1)
    {
        memset(children, 0, sizeof(TrieNode*) * 26);
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int l = words.size();
        int li, lj;
        TrieNode *root = new TrieNode();
        TrieNode *node;
        bool flag, flagI;
        vector<vector<int>> res;

        for(int i=0;i<l;i++)
        {
            node = root;
            for(int j=words[i].size()-1;j>=0;j--)
            {
                if(node->children[words[i][j]-'a'] == 0)
                    node->children[words[i][j]-'a'] = new TrieNode();
                node->wordsIdxList.push_back(i);
                node = node->children[words[i][j]-'a'];
            }
            node->wordIdx = i;
        }

        for(int i=0;i<l;i++)
        {
            node = root;
            li = words[i].size();
            flagI = false;
            if(root->wordIdx >= 0 && i != root->wordIdx)
            {
                flag = false;
                for(int k=0;k<li;k++)
                {
                    if(words[i][k] != words[i][li-k-1])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    res.push_back({i, root->wordIdx});
                }
            }
            for(int j=0;j<li;j++)
            {
                if(node->children[words[i][j]-'a'] != 0)
                {
                    node = node->children[words[i][j]-'a'];
                }
                else
                {
                    flagI = true;
                    break;
                }
                if(node->wordIdx >= 0 && i != node->wordIdx)
                {
                    flag = false;
                    for(int k=j+1;k<li;k++)
                    {
                        if(words[i][k] != words[i][li-k+j])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        res.push_back({i, node->wordIdx});
                    }
                }
            }
            if(!flagI)
            {
                for(auto it=node->wordsIdxList.begin();it!=node->wordsIdxList.end();it++)
                {
                    if(i == *it)
                        continue;

                    lj = words[*it].size();
                    flag = false;
                    for(int j=0;j<lj-li;j++)
                    {
                        if(words[*it][j] != words[*it][lj-li-j-1])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        res.push_back({i, *it});
                    }
                }
            }
        }
        return res;
    }
};