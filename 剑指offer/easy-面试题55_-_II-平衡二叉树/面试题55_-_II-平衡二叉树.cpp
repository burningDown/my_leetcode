/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int traverse(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int l = traverse(root->left);
        int r = traverse(root->right);

        if(l < 0 || r < 0 || abs(l-r)>1)
            return -1;

        return (l > r ? l : r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return traverse(root) >= 0;
    }
};