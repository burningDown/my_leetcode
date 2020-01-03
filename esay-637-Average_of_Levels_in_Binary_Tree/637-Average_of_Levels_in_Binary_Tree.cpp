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
    queue<pair<TreeNode*, int>> tracking;
    vector<pair<long, int>> avgArray;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        tracking.push(pair<TreeNode*, int>(root, 0));
        while(!tracking.empty())
        {
            auto &node = tracking.front();

            if(node.second >= avgArray.size())
                avgArray.push_back(pair<long, int>(.0, 0));
            
            avgArray[node.second].first += node.first->val;
            avgArray[node.second].second++;

            if(node.first->left != NULL)
                tracking.push(pair<TreeNode*, int>(node.first->left, node.second+1));
            if(node.first->right != NULL)
                tracking.push(pair<TreeNode*, int>(node.first->right, node.second+1));
                
            tracking.pop();
        }
        int l = avgArray.size();
        vector<double> result(l, 0);
        for(int i=0;i<l;i++)
        {
            result[i] = double(avgArray[i].first) / avgArray[i].second;
        }
        return result;
    }
};