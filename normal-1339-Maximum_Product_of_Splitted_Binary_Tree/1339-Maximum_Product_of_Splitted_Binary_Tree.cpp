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
    long long maxP;
    int sum;

    int traverse(TreeNode *node)
    {
        if(node == NULL)
            return 0;
        const int left = traverse(node->left);
        const int right = traverse(node->right);
        const int &subSum = left + right + node->val;

        const long long &product = (long long)(sum - subSum) * subSum;
        if(product > maxP)
            maxP = product;
        return subSum;
    }
    void traverse_for_sum(TreeNode *node)
    {
        if(node == NULL)
            return;
        traverse_for_sum(node->left);
        traverse_for_sum(node->right);
        sum += node->val;
    }
public:
    Solution(): maxP(0), sum(0){}
    int maxProduct(TreeNode* root) {
        traverse_for_sum(root);
        traverse(root);
        return maxP % (1000000000+7);
    }
};