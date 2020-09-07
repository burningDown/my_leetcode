/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode *fast = head, *slow = head, *pre = head;
        bool isDouble = false;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast == NULL)
            {
                isDouble = false;
                break;
            }
            fast = fast->next;
            if(fast == NULL)
            {
                isDouble = true;
                break;
            }
            pre = slow;
            slow = slow->next;
        }
        TreeNode *root = NULL;
        TreeNode *left = NULL;
        TreeNode *right = NULL;

        if(pre != slow)
        {
            pre->next = NULL;
            root = new TreeNode(slow->val);
            left = sortedListToBST(head);
            right = sortedListToBST(slow->next);
        }
        else if(isDouble)
        {
            root = new TreeNode(slow->next->val);
            pre->next = NULL;
            left = sortedListToBST(head);
            right = NULL;
        }
        else
        {
            root = new TreeNode(slow->val);
            left = NULL;
            right = NULL;
        }
        root->left = left;
        root->right = right;
        return root;
    }
};