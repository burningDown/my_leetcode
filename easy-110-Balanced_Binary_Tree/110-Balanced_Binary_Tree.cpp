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
    int getHeight(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int l = getHeight(root->left);
        if(l < 0)
            return -1;
        int r = getHeight(root->right);
        if(r < 0)
            return -1;
        if(abs(l - r) > 1)
            return -1;
        return max(l, r) + 1;
        
    }
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
};