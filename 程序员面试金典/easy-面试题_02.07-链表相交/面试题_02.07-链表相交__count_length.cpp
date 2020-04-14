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
        int l1, l2;
        ListNode *p1, *p2;
        for(l1=1, p1=headA;p1->next!=NULL;l1++, p1=p1->next)
            ;
        for(l2=1, p2=headB;p2->next!=NULL;l2++, p2=p2->next)
            ;
        
        if(p1 != p2)
            return NULL;
        
        p1 = headA;
        p2 = headB;
        if(l1 > l2)
        {
            for(int i=0;i<l1-l2;i++)
                p1 = p1->next;
        }
        else if(l2 > l1)
        {
            for(int i=0;i<l2-l1;i++)
                p2 = p2->next;
        }
        while(p1 != NULL && p2 != NULL)
        {
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};