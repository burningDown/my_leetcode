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
    bool compare(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL || root1->val != root2->val)
            return false;
        
        return compare(root1->left, root2->right) && compare(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return compare(root->left, root->right);
    }
};