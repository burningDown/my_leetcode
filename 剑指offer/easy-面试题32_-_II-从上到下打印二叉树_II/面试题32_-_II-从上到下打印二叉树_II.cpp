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
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        queue<TreeNode*> *pCurrent;
        queue<TreeNode*> *pCandidate;
        vector<vector<int>> result;

        if(root == NULL)
            return result;
        
        result.reserve(500);
        pCurrent = &q1;
        pCandidate = &q2;
        pCurrent->push(root);
        while(!q1.empty() || !q2.empty())
        {
            if(!q1.empty())
            {
                pCurrent = &q1;
                pCandidate = &q2;
            }
            else
            {
                pCurrent = &q2;
                pCandidate = &q1;
            }
            vector<int> layer;
            layer.reserve(500);
            while(!pCurrent->empty())
            {
                TreeNode *node = pCurrent->front();
                pCurrent->pop();

                layer.push_back(node->val);
                if(node->left != NULL)
                    pCandidate->push(node->left);
                if(node->right != NULL)
                    pCandidate->push(node->right);
            }
            result.push_back(layer);
        }
        return result;
    }
};