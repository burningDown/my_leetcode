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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode virtualHead(INT_MIN);
        ListNode *node = &virtualHead;
        virtualHead.next = head;

        while(node->next != NULL)
        {
            if(node->next->val == val)
            {
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return virtualHead.next;
    }
};