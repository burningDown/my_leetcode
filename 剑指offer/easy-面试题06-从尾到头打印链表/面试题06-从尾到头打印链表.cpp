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
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        result.reserve(10010);
        
        ListNode *node = head;
        while(node != NULL)
        {
            result.push_back(node->val);
            node = node->next;
        }

        const int l = result.size();
        for(int i=0;i<l/2;i++)
        {
            int temp = result[i];
            result[i] = result[l-i-1];
            result[l-i-1] = temp;
        }
        return result;
    }
};