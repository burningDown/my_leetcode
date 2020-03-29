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
    TreeNode* nodeQueue1[1000];
    TreeNode* nodeQueue2[1000];
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int q1 = 0, q2 = 0;
        int depth = 0;
        vector<vector<int>> result;

        if(root == NULL)
            return result;

        result.reserve(1000);
        nodeQueue1[q1++] = root;
        while(q1 > 0 || q2 > 0)
        {
            vector<int> layer;
            layer.reserve(20);
            while(true)
            {
                if(depth % 2 == 0)
                {
                    if(q1 == 0)
                        break;
                    
                    TreeNode *node = nodeQueue1[--q1];
                    layer.push_back(node->val);
                    if(node->left != NULL)
                        nodeQueue2[q2++] = node->left;
                    if(node->right != NULL)
                        nodeQueue2[q2++] = node->right;
                }
                else
                {
                    if(q2 == 0)
                        break;
                    
                    TreeNode *node = nodeQueue2[--q2];
                    layer.push_back(node->val);
                    if(node->right != NULL)
                        nodeQueue1[q1++] = node->right;
                    if(node->left != NULL)
                        nodeQueue1[q1++] = node->left;
                }
            }
            depth++;
            result.push_back(layer);
        }
        return result;
    }
};