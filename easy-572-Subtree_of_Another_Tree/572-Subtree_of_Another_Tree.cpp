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
    bool check(TreeNode *s, TreeNode *t)
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL || s->val != t->val)
            return false;
        
        if(check(s->left, t->left) && check(s->right, t->right))
            return true;
        
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL)
            return true;
        if(s == NULL)
            return false;
        
        if(check(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t))
            return true;
        return false;
    }
};