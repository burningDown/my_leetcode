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
    void traverse(TreeNode *root, vector<int> &rightSide, int depth, int &maxDepth)
    {
        if(root == NULL)
            return;
        
        if(depth > maxDepth)
        {
            maxDepth = depth;
            rightSide.push_back(root->val);
        }
        traverse(root->right, rightSide, depth+1, maxDepth);
        traverse(root->left, rightSide, depth+1, maxDepth);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        int maxDepth = -1;

        traverse(root, rightSide, 0, maxDepth);

        return rightSide;
    }
};