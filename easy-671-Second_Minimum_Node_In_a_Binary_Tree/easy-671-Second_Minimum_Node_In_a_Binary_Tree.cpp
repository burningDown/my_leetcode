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
    int findSecondMinimumValue(TreeNode* root) {
        TreeNode *pNode;
        int secondMin = -1;

        queue<TreeNode*> traverseQueue;
        traverseQueue.push(root);
        while(!traverseQueue.empty())
        {
            pNode = traverseQueue.front();
            traverseQueue.pop();

            if(pNode->left != NULL)
            {
                if(pNode->left->val == root->val)
                {
                    traverseQueue.push(pNode->left);
                }
                else if(secondMin == -1 || pNode->left->val < secondMin)
                    secondMin = pNode->left->val;
            }

            if(pNode->right != NULL)
            {
                if(pNode->right->val == root->val)
                {
                    traverseQueue.push(pNode->right);
                }
                else if(secondMin == -1 || pNode->right->val < secondMin)
                    secondMin = pNode->right->val;
            }
        }

        return secondMin;
    }
};