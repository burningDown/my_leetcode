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
    int helper(TreeNode *root, int sum, unordered_map<int, int> &integralMap, int pathSum)
    {
        if(root == NULL)
            return 0;

        int count = 0;

        pathSum += root->val;

        if(integralMap.count(pathSum - sum) > 0)
            count += integralMap[pathSum - sum];
        integralMap[pathSum]++;

        count += helper(root->left, sum, integralMap, pathSum);
        count += helper(root->right, sum, integralMap, pathSum);

        integralMap[pathSum]--;
        if(integralMap[pathSum] == 0)
            integralMap.erase(pathSum);
        
        return count;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> integralMap;
        integralMap[0] = 1;

        return helper(root, sum, integralMap, 0);
    }
};