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
    TreeNode *helper(TreeNode *root, TreeNode *p, bool &detected)
    {
        if(root == NULL)
            return NULL;
        
        TreeNode *node;
        if((node = helper(root->left, p, detected)) != NULL)
            return node;

        if(detected)
            return root;
        
        if(root == p)
            detected = true;
        if((node = helper(root->right, p, detected)) != NULL)
            return node;
        return NULL;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool detected = false;
        return helper(root, p, detected);
    }
};