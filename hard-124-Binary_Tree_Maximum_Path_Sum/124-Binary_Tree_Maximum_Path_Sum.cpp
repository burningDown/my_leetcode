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
    int helper(TreeNode *root, int &maxSum)
    {
        if(root == NULL)
            return 0;

        int left = max(0, helper(root->left, maxSum));
        int right = max(0, helper(root->right, maxSum));
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};