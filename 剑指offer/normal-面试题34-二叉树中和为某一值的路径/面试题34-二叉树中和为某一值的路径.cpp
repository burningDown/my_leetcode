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
    void dfs(TreeNode *root, int sum, int currentSum, vector<vector<int>> &result, vector<int> &path)
    {
        path.push_back(root->val);
        currentSum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(currentSum == sum)
                result.push_back(path);
        }
        else
        {
            if(root->left != NULL)
                dfs(root->left, sum, currentSum, result, path);
            
            if(root->right != NULL)
                dfs(root->right, sum, currentSum, result, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;

        if(root == NULL)
            return result;
        
        result.reserve(1000);
        path.reserve(1000);
        dfs(root, sum, 0, result, path);
        return result;
    }
};