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
    int trackback(TreeNode *root, bool rob, unordered_map<TreeNode*, vector<int>> &dp)
    {
        if(root == NULL)
            return 0;
        if(dp.find(root) != dp.end())
        {
            if(dp[root][int(rob)] >= 0)
                return dp[root][int(rob)];
        }
        else
            dp[root] = vector<int>(2, -1);

        int res;
        if(rob)
            res = trackback(root->left, false, dp) + trackback(root->right, false, dp);
        else
            res = max(root->val + trackback(root->left, true, dp) + trackback(root->right, true, dp), trackback(root->left, false, dp) + trackback(root->right, false, dp));
        
        dp[root][int(rob)] = res;
        return res;
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> dp;
        return trackback(root, false, dp);
    }
};