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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *node = head;
        if(head == NULL)
            return NULL;
        while(node->next != NULL)
        {
            if(node->next->val == val)
                node->next = node->next->next;
            else
                node = node->next;
        }
        if(head->val == val)
            head = head->next;
        return head;
    }
};