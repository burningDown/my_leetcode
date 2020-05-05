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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int idx = -1;
        const int l = lists.size();

        ListNode virtualhead(0);
        ListNode *node = &virtualhead;
        while(true)
        {
            idx = -1;
            for(int i=0;i<l;i++)
            {
                if(lists[i] != NULL && (idx < 0 || lists[i]->val < lists[idx]->val))
                    idx = i;
            }

            if(idx >= 0)
            {
                node->next = lists[idx];
                lists[idx] = lists[idx]->next;
                node = node->next;
                node->next = NULL;
            }
            else
                break;
        }

        return virtualhead.next;
    }
};