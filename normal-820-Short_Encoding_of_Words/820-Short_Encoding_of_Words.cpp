struct WordTreeNode
{
    bool containWord;
    unordered_map<char, WordTreeNode*> childList;
    WordTreeNode(bool containWord)
    {
        this->containWord = containWord;
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        WordTreeNode root(false);
        WordTreeNode *node;
        int length = 0;
        for(string s : words)
        {
            const int l = s.size();
            node = &root;
            for(int i=l-1;i>=0;i--)
            {
                if(node->childList.count(s[i]))
                {
                    if(i == 0)
                        node->childList[s[i]]->containWord = true;
                }
                else
                {
                    if(node->childList.size() > 0 || i == l-1)
                        length += l - i;
                    length++;
                    if(i == 0)
                        node->childList[s[i]] = new WordTreeNode(true);
                    else
                        node->childList[s[i]] = new WordTreeNode(false);
                }
                node = node->childList[s[i]];
            }
        }
        return length;
    }
};