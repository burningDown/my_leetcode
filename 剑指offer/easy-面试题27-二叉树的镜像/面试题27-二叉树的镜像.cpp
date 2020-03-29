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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        if(root->left != NULL)
            mirrorTree(root->left);
        if(root->right != NULL)
            mirrorTree(root->right);
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;
        return root;
    }
};