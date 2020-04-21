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
    bool preTraverse(TreeNode *root, long &pre)
    {
        if(root == NULL)
            return true;
        
        if(!preTraverse(root->left, pre))
            return false;
        if(root->val <= pre)
            return false;
        pre = root->val;
        if(!preTraverse(root->right, pre))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        long pre = INT_MIN;
        pre -= 10;
        return preTraverse(root, pre);
    }
};