/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> result;
        queue<pair<TreeNode*, int>> stateQueue;
        ListNode virtualHead(0);
        ListNode *node;
        pair<TreeNode*, int> state;

        stateQueue.push({tree, 0});
        node = &virtualHead;
        while(!stateQueue.empty())
        {
            state = stateQueue.front();
            stateQueue.pop();
            if(state.first == NULL)
                continue;

            if(state.second > result.size())
            {
                result.push_back(virtualHead.next);
                virtualHead.next = new ListNode(state.first->val);
                node = virtualHead.next;
            }
            else
            {
                node->next = new ListNode(state.first->val);
                node = node->next;
            }

            stateQueue.push({state.first->left, state.second+1});
            stateQueue.push({state.first->right, state.second+1});
        }
        if(virtualHead.next != NULL)
            result.push_back(virtualHead.next);
        return result;
    }
};