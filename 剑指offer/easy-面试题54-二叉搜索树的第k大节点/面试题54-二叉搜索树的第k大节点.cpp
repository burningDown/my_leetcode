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
    int globalK, res;
    void traverse(TreeNode* root)
    {
        if(root->right != NULL)
            traverse(root->right);
        if(globalK == 0)
            return;
        globalK--;
        if(globalK == 0)
        {
            res = root->val;
            return;
        }
        if(root->left != NULL)
            traverse(root->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        globalK = k;
        traverse(root);
        return res;
    }
};