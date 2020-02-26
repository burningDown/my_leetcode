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
    unordered_map<TreeNode*, TreeNode*> path;
    int tempPath[100];
    int p;
    vector<string> result;
    char buf[200];

    void traversal(TreeNode *node, TreeNode* pre)
    {
        path[node] = pre;
        if(node->left == NULL && node->right == NULL)
        {
            p = 0;
            for(TreeNode *i = node;i!=NULL;i=path[i])
            {
                tempPath[p++] = i->val;
            }
            if(p>0)
            {
                sprintf(buf, "%d", tempPath[--p]);
                while(p>0)
                {
                    sprintf(buf+strlen(buf), "->%d", tempPath[--p]);
                }
            }
            result.push_back(string(buf));
        }
        if(node->left != NULL)
            traversal(node->left, node);
        if(node->right != NULL)
            traversal(node->right, node);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return result;
        traversal(root, NULL);
        return result;
    }
};