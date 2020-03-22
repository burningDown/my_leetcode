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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *node, *tempNode;
        vector<ListNode*> result;
        int l = 0;
        for(node = root;node!=NULL;node=node->next)
            ++l;
        if(l <= k)
        {
            result.reserve(k+10);
            for(node=root;node!=NULL;)
            {
                tempNode = node;
                node = node->next;
                tempNode->next = NULL;
                result.push_back(tempNode);
            }
            while(result.size() < k)
                result.push_back(NULL);
        }
        else
        {
            node = root;
            result.reserve(l/k+10);
            for(int i=l%k;i>0;i--)
            {
                result.push_back(node);
                for(int j=0;j<l/k+1;j++)
                {
                    tempNode = node;
                    node=node->next;
                }
                tempNode->next = NULL;
            }
            for(int i=k-l%k;i>0;i--)
            {
                result.push_back(node);
                for(int j=0;j<l/k;j++)
                {
                    tempNode = node;
                    node=node->next;
                }
                tempNode->next = NULL;
            }
        }
        return result;
    }
};