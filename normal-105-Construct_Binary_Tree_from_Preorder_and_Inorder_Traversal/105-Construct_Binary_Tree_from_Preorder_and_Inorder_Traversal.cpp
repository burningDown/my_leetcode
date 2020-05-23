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
    TreeNode *build(vector<int> &preorder, int pi, int pj, vector<int> &inorder, int ii, int ij)
    {
        if(pi > pj)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[pi]);
        int left;
        
        for(left = 0; pi + left <= pj; left++)
        {
            if(inorder[ii + left] == preorder[pi])
                break;
        }

        root->left = build(preorder, pi + 1, pi + left, inorder, ii, ii + left - 1);
        root->right = build(preorder, pi + left + 1, pj, inorder, ii + left + 1, ij);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};