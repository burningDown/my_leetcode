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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = head, *p2;
        while(p1 != NULL)
        {
            p2 = p1;
            while(p2->next != NULL)
            {
                if(p1->val == p2->next->val)
                    p2->next = p2->next->next;
                else
                    p2 = p2->next;
            }
            p1 = p1->next;
        }
        return head;
    }
};