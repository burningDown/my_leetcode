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
        vector<ListNode*> nodeArray;
        ListNode *node;
        int i, j;

        nodeArray.reserve(125);
        for(node = head;node!=NULL;node=node->next)
            nodeArray.push_back(node);
        
        node = nodeArray[0];
        i = 0;
        j = nodeArray.size()-1;
        while(i<j)
        {
            while(i<j)
            {
                if(nodeArray[j]->val < x)
                {
                    nodeArray[i] = nodeArray[j];
                    ++i;
                    break;
                }
                --j;
            }
            while(i<j)
            {
                if(nodeArray[i]->val >= x)
                {
                    nodeArray[j] = nodeArray[i];
                    --j;
                    break;
                }
                ++i;
            }
        }
        nodeArray[i] = node;
        node = head = nodeArray[0];
        for(i=1;i<nodeArray.size();i++)
        {
            node->next = nodeArray[i];
            node = node->next;
        }
        node->next = NULL;
        return head;
    }
};