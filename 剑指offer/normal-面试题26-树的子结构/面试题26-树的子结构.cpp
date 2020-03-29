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
    TreeNode *findNode(TreeNode *root, TreeNode *checkNode)
    {
        if(root == NULL || checkNode == NULL)
            return NULL;
        if(root->val == checkNode->val)
            return root;
        TreeNode *left, *right;
        if((left = findNode(root->left, checkNode)) != NULL)
            return left;
        if((right = findNode(root->right, checkNode)) != NULL)
            return right;
        return NULL;
    }
    bool compareTree(TreeNode *root1, TreeNode *root2)
    {
        if(root2 == NULL)
            return true;
        if(root1 == NULL)
            return false;
        if(root1->val != root2->val)
            return false;
        return compareTree(root1->left, root2->left) && compareTree(root1->right, root2->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        TreeNode *node = findNode(A, B);
        if(node == NULL)
            return false;
        return compareTree(node, B);
    }
};