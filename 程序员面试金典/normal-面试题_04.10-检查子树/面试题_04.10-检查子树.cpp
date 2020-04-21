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
    bool checkEquivalent(TreeNode *t1, TreeNode *t2)
    {
        vector<TreeNode*> nodes;
        queue<vector<TreeNode*>> stateQueue;

        stateQueue.push({t1, t2});
        while(!stateQueue.empty())
        {
            nodes = stateQueue.front();
            stateQueue.pop();

            if(nodes[0] == NULL && nodes[1] == NULL)
                continue;
            else if(nodes[0] == NULL || nodes[1] == NULL)
                return false;
            
            if(nodes[0]->val != nodes[1]->val)
                return false;
            
            stateQueue.push({nodes[0]->left, nodes[1]->left});
            stateQueue.push({nodes[0]->right, nodes[1]->right});
        }
        return true;
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t2 == NULL)
            return true;
        if(t1 == NULL)
            return false;

        queue<TreeNode*> stateQueue;
        TreeNode *node;

        stateQueue.push(t1);
        while(!stateQueue.empty())
        {
            node = stateQueue.front();
            stateQueue.pop();

            if(node == NULL)
                continue;
            
            if(node->val == t2->val)
            {
                if(checkEquivalent(node, t2))
                    return true;
            }

            stateQueue.push(node->left);
            stateQueue.push(node->right);
        }
        return false;
    }
};