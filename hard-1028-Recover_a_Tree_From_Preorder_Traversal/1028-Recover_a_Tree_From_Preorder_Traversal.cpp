class Solution {
private:
    stack<pair<TreeNode*, int>> mStack;
public:
    TreeNode* recoverFromPreorder(string S) {
        TreeNode *current, *root;
        const int &l = S.size();
        int i=0, value=0, dp=0, ndp=0;
        while(i<l)
        {
            const auto &s = S[i];
            if(s>='0' && s <= '9')
            {
                value *= 10;
                value += s - '0';
            }
            else
                break;
            i++;
        }
        root = current = new TreeNode(value);
        value = 0;

        while(i<l)
        {
            while(i<l)
            {
                const auto &s = S[i];
                if(s == '-' && value == 0)
                    ndp++;
                else if(s>='0' && s <= '9')
                {
                    value *= 10;
                    value += s - '0';
                }
                else
                    break;
                i++;
            }

            if(ndp > dp)
            {
                current->left = new TreeNode(value);
                mStack.emplace(current, dp);
                current = current->left;
                dp = ndp;
            }
            else
            {
                while(1)
                {
                    const pair<TreeNode*, int> snode = mStack.top();
                    mStack.pop();
                    if(ndp > snode.second)
                    {
                        current = snode.first;
                        break;
                    }
                }
                current->right = new TreeNode(value);
                current = current->right;
                dp = ndp;
            }
            ndp = 0;
            value = 0;
        }
        return root;
    }
};