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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode virtualHead(0);
        ListNode *node = &virtualHead, *temp;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;

        while(l1 != NULL && l2 != NULL)
        {
            temp = new ListNode((l1->val + l2->val + carry)%10);
            temp->next = node->next;
            node->next = temp;
            node = node->next;
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            temp = new ListNode((l1->val + carry)%10);
            temp->next = node->next;
            node->next = temp;
            node = node->next;
            carry = (l1->val + carry)/10;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            temp = new ListNode((l2->val + carry)%10);
            temp->next = node->next;
            node->next = temp;
            node = node->next;
            carry = (l2->val + carry)/10;
            l2 = l2->next;
        }
        if(carry > 0)
        {
            temp = new ListNode(carry);
            temp->next = node->next;
            node->next = temp;
            node = node->next;
        }
        return virtualHead.next;
    }
};