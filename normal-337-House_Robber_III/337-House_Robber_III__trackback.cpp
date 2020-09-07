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
    int trackback(TreeNode *root, bool rob)
    {
        if(root == NULL)
            return 0;
        int res;
        if(rob)
            res = trackback(root->left, false) + trackback(root->right, false);
        else
            res = max(root->val + trackback(root->left, true) + trackback(root->right, true), trackback(root->left, false) + trackback(root->right, false));
        return res;
    }
public:
    int rob(TreeNode* root) {
        return trackback(root, false);
    }
};