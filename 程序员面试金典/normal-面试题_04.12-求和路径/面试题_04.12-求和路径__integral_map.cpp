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
    int helper(TreeNode *root, int sum, vector<int> &dp)
    {
        if(root == NULL)
            return 0;
        
        dp.push_back(dp.back() + root->val);

        int res = 0;
        const int l = dp.size();

        for(int i=0;i<l-1;i++)
        {
            if(dp.back() - dp[i] == sum)
                res++;
        }

        res += helper(root->left, sum, dp);
        res += helper(root->right, sum, dp);

        dp.pop_back();
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> dp(1, 0);
        dp.reserve(10010);

        return helper(root, sum, dp);
    }
};