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
    TreeNode *helper(TreeNode *root, TreeNode *node)
    {
        TreeNode *lNode;

        lNode = root->left == NULL ? root : helper(root->left, root);
        root->right = root->right == NULL ? node : helper(root->right, node);

        root->left = NULL;
        return lNode;
    }
public:
    TreeNode* convertBiNode(TreeNode* root) {
        return root == NULL ? NULL : helper(root, NULL);
    }
};