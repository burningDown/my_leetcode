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
        stack<int> l1Stack;
        stack<int> l2Stack;
        ListNode *node;
        ListNode *newL;
        int carry = 0;
        int d1, d2;

        for(node = l1;node!=NULL;node=node->next)
            l1Stack.push(node->val);
        for(node = l2;node!=NULL;node=node->next)
            l2Stack.push(node->val);

        node = NULL;
        while(!l1Stack.empty() && !l2Stack.empty())
        {
            d1 = l1Stack.top();
            d2 = l2Stack.top();
            l1Stack.pop();
            l2Stack.pop();
            newL = new ListNode((d1 + d2 + carry)%10);
            carry = (d1 + d2 + carry)/10;
            newL->next = node;
            node = newL;
        }
        while(!l1Stack.empty())
        {
            d1 = l1Stack.top();
            l1Stack.pop();
            newL = new ListNode((d1 + carry)%10);
            carry = (d1 + carry)/10;
            newL->next = node;
            node = newL;
        }
        while(!l2Stack.empty())
        {
            d2 = l2Stack.top();
            l2Stack.pop();
            newL = new ListNode((d2 + carry)%10);
            carry = (d2 + carry)/10;
            newL->next = node;
            node = newL;
        }
        if(carry > 0)
        {
            newL = new ListNode(carry);
            newL->next = node;
            node = newL;
        }
        return newL;
    }
};