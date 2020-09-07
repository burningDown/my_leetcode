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
    TreeNode *helper(vector<int> &preorder, int l, int r)
    {
        if(l == r)
            return new TreeNode(preorder[l]);
        if(l > r)
            return NULL;
            
        int m;
        for(m = l+1;m<=r;m++)
        {
            if(preorder[m] > preorder[l])
                break;
        }

        TreeNode *node = new TreeNode(preorder[l]);
        node->left = helper(preorder, l+1, m-1);
        node->right = helper(preorder, m, r);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};