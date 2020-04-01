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
    TreeNode* constructTree(vector<int> &preorder, int pi, int pj, vector<int> &inorder, int ii, int ij)
    {
        if(pi > pj || ii > ij)
            return NULL;
        int i;
        TreeNode *node = new TreeNode(preorder[pi]);
        for(i = ii;i<=ij;i++)
            if(inorder[i] == preorder[pi])
                break;
        int leftDepth = i - ii + 1;
        node->left = constructTree(preorder, pi+1, pi+leftDepth-1, inorder, ii, ii+leftDepth-2);
        node->right = constructTree(preorder, pi+leftDepth, pj, inorder, ii+leftDepth, ij);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};