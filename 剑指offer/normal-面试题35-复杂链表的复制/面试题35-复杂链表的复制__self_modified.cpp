/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *node = head;
        Node *newNode;
        Node *temp;
        Node newList(0);
        
        if(head == NULL)
            return NULL;
        while(node != NULL)
        {
            newNode = new Node(node->val);
            temp = node->next;
            node->next = newNode;
            newNode->next = temp;
            node = temp;
        }
        node = head;
        while(node != NULL)
        {
            newNode = node->next;
            newNode->random = node->random == NULL ? NULL : node->random->next;
            node = newNode->next;
        }
        node = head;
        newList.next = node->next;
        while(node != NULL)
        {
            newNode = node->next;
            node->next = node->next == NULL ? NULL : node->next->next;
            newNode->next = newNode->next == NULL ? NULL : newNode->next->next;
            node = node->next;
        }
        return newList.next;
    }
};