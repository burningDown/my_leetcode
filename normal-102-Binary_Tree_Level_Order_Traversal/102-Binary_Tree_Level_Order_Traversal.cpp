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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> result;
        vector<int> layer;
        queue<pair<TreeNode*, int>> stateQueue;

        stateQueue.push({root, 0});
        while(!stateQueue.empty())
        {
            auto p = stateQueue.front();
            stateQueue.pop();
            if(p.first == NULL)
                continue;
            
            if(p.second > result.size())
            {
                result.push_back(layer);
                layer.clear();
            }

            layer.push_back(p.first->val);
            
            stateQueue.push({p.first->left, p.second + 1});
            stateQueue.push({p.first->right, p.second + 1});
        }
        result.push_back(layer);
        return result;
    }
};