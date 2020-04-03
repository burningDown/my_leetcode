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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = head;
        if(head == NULL)
            return NULL;
        ListNode *current = head->next;
        ListNode *next;

        pre->next = NULL;
        while(current != NULL)
        {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};