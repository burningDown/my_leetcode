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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *p1 = headA, *p2 = headB;
        if(p1 == p2)
            return p1;
        while(p1->next != NULL || p2->next != NULL)
        {
            p1 = p1->next == NULL ? headB : p1->next;
            p2 = p2->next == NULL ? headA : p2->next;

            if(p1 == p2)
                return p1;
        }
        return NULL;
    }
};