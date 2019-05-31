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
    int sumRootToLeaf(TreeNode* root, int val=0) {
        if(root == NULL)
            return 0;
        val = ((val<<1)|root->val);
        if(root->left==NULL&&root->right==NULL)
            return val;
        return sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};