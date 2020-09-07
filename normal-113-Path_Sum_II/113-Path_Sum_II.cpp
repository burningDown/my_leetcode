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
    void trackback(TreeNode *root, vector<vector<int>> &res, vector<int> &path, int currentSum, int sum)
    {
        if(root == NULL)
            return;
            
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && currentSum + root->val == sum)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }

        trackback(root->left, res, path, currentSum + root->val, sum);
        trackback(root->right, res, path, currentSum + root->val, sum);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;

        trackback(root, res, path, 0, sum);

        return res;
    }
};