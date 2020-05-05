/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* pairMerge(ListNode *list1, ListNode *list2)
    {
        ListNode virtualhead;
        ListNode *node = &virtualhead;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                node->next = list1;
                list1 = list1->next;
                node = node->next;
                node->next = NULL;
            }
            else
            {
                node->next = list2;
                list2 = list2->next;
                node = node->next;
                node->next = NULL;
            }
        }
        if(list1 != NULL)
            node->next = list1;
        else if(list2 != NULL)
            node->next = list2;

        return virtualhead.next;
    }

    void divideMerge(vector<ListNode*> &lists)
    {
        const int l = lists.size();
        for(int step = 1;step < l;step *= 2)
        {
            for(int i = step;i<l;i+=2 * step)
            {
                lists[i-step] = pairMerge(lists[i-step], lists[i]);
                lists[i] = NULL;
            }
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        divideMerge(lists);
        return lists[0];
    }
};