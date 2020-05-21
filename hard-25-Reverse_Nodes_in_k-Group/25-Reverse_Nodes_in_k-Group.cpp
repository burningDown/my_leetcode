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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode virtualHead(0);
        ListNode *kHead, *node, *pre, *temp, *nextNode, *lastHead;
        bool flag = false;

        virtualHead.next = head;
        lastHead = &virtualHead;
        kHead = nextNode = head;
        while(true)
        {
            kHead = nextNode;
            for(int i=0;i<k;i++)
            {
                if(nextNode == NULL)
                {
                    flag = true;
                    lastHead->next = kHead;
                    break;
                }
                nextNode = nextNode->next;
            }
            if(flag)
                break;
            
            pre = kHead;
            node = kHead->next;
            while(node != nextNode)
            {
                temp = node->next;
                node->next = pre;
                pre = node;
                node = temp;
            }
            lastHead->next = pre;
            lastHead = kHead;
        }

        return virtualHead.next;
    }
};