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
    void randomMerge(vector<vector<int>> &allResult, vector<int> &result, vector<int> &s1, int i1, vector<int> &s2, int i2)
    {
        if(i1 >= s1.size() && i2 >= s2.size())
        {
            allResult.push_back(result);
            return;
        }
        if(i1 < s1.size())
        {
            result.push_back(s1[i1]);
            randomMerge(allResult, result, s1, i1+1, s2, i2);
            result.pop_back();
        }
        if(i2 < s2.size())
        {
            result.push_back(s2[i2]);
            randomMerge(allResult, result, s1, i1, s2, i2+1);
            result.pop_back();
        }
    }
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root == NULL)
            return {{}};
        
        vector<vector<int>> result;
        vector<int> buffer = {root->val};

        vector<vector<int>> leftSeq = BSTSequences(root->left);
        vector<vector<int>> rightSeq = BSTSequences(root->right);
        
        for(auto l : leftSeq)
        {
            for(auto r : rightSeq)
            {
                randomMerge(result, buffer, l, 0, r, 0);
            }
        }

        return result;
    }
};