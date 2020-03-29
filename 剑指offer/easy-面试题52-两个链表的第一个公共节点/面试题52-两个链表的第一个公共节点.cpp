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
        ListNode *pA = headA, *pB = headB;
        if(headA == NULL || headB == NULL)
            return NULL;
        while(true)
        {
            if(pA == NULL && pB == NULL)
                return NULL;
            if(pA == NULL)
                pA = headA;
            else if(pB == NULL)
                pB = headB;
            if(pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};