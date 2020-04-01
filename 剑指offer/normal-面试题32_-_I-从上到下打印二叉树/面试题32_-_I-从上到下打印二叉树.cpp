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
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> stateQueue;
        vector<int> result;
        
        result.reserve(1010);
        stateQueue.push(root);
        while(!stateQueue.empty())
        {
            TreeNode *node = stateQueue.front();
            stateQueue.pop();
            if(node == NULL)
                continue;
            result.push_back(node->val);
            stateQueue.push(node->left);
            stateQueue.push(node->right);
        }
        return result;
    }
};