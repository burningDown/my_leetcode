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
    bool helper(TreeNode *root, int &pre, bool &isStart)
    {
        if(root == NULL)
            return true;
        
        if(!helper(root->left, pre, isStart))
            return false;
        
        if(!isStart && root->val <= pre)
            return false;

        isStart = false;
        pre = root->val;
        
        if(!helper(root->right, pre, isStart))
            return false;
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        int pre = 0;
        bool isStart = true;
        return helper(root, pre, isStart);
    }
};