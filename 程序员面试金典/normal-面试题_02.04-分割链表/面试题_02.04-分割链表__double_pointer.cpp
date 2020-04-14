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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        ListNode *node, *tempNode;
        ListNode *newHead, *newTail;
        
        newHead = newTail = head;
        for(node=head->next;node!=NULL;)
        {
            if(node->val < x)
            {
                tempNode = node;
                node = node->next;
                tempNode->next = newHead;
                newHead = tempNode;
            }
            else
            {
                tempNode = node;
                node = node->next;
                newTail->next = tempNode;
                newTail = tempNode;
                newTail->next = NULL;
            }
        }
        newTail->next = NULL;
        return newHead;
    }
};