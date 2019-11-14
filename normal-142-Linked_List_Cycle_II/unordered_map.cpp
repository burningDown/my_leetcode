/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<unordered_map>
class Solution {
private:
    unordered_map<ListNode*, bool> flagMap;
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *node = head;
        while(node != NULL)
        {
            if(!flagMap[node])
            {
                flagMap[node] = true;
                node = node->next;
            }
            else
            {
                break;
            }
        }
        return node;
    }
};