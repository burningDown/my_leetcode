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
    vector<int> order;
    void traversal(TreeNode* node)
    {
        if(node == NULL)
            return;
        traversal(node->left);
        traversal(node->right);
        order.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        traversal(root);
        return order;
    }
};