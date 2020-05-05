/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp
{
    bool operator()(ListNode *node1, ListNode *node2)
    {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> nodeQueue;
        ListNode virtualnode(0);
        ListNode *node = &virtualnode, *temp;

        for(auto &n : lists)
        {
            if(n != NULL)
                nodeQueue.push(n);
        }

        while(!nodeQueue.empty())
        {
            temp = nodeQueue.top();
            nodeQueue.pop();

            if(temp->next != NULL)
                nodeQueue.push(temp->next);
            node->next = temp;
            node = node->next;
            node->next = NULL;
        }
        return virtualnode.next;
    }
};