/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode *helper(TreeNode *root)
    {
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        TreeNode *tail = root;
        
        if(l != NULL)
        {
            tail->left = NULL;
            tail->right = l;
            tail = helper(l);
        }
        if(r != NULL)
        {
            tail->left = NULL;
            tail->right = r;
            tail = helper(r);
        }

        return tail;
    }
public:
    void flatten(TreeNode* root) {
        if(root != NULL)
            helper(root);
    }
};