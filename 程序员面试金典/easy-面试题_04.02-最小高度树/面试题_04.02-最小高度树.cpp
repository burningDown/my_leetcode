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
    TreeNode *buildBinaryTree(vector<int> &nums, int start, int end)
    {
        if(start > end)
            return NULL;
        if(start == end)
            return new TreeNode(nums[start]);
        
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildBinaryTree(nums, start, mid-1);
        node->right = buildBinaryTree(nums, mid+1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBinaryTree(nums, 0, nums.size()-1);
    }
};