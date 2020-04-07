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
    bool isPalindrome(ListNode* head) {
        ListNode *reversedHead, *fast, *slow, *pre = NULL;
        fast = slow = head;

        if(head == NULL)
            return true;
        while(true)
        {
            if(fast->next != NULL)
                fast = fast->next;
            else
                break;

            if(fast->next != NULL)
                fast = fast->next;
            else
                break;
            
            slow = slow->next;
        }
        
        pre = NULL;
        while(slow != NULL)
        {
            reversedHead = slow->next;
            slow->next = pre;
            pre = slow;
            slow = reversedHead;
        }
        reversedHead = pre;

        slow = head;
        fast = reversedHead;

        while(slow!=NULL)
        {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};