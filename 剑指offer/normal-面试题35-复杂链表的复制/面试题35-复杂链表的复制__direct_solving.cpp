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
        unordered_map<Node*, Node*> nodeMap;
        
        nodeMap.reserve(1100);

        Node *node = head;
        Node newList(0);
        Node *newNode = &newList;
        for(int i = 0;node != NULL;i++, node = node->next, newNode = newNode->next)
        {
            newNode->next = new Node(node->val);
            nodeMap[node] = newNode->next;
        }

        newNode = newList.next;
        node = head;
        for(int i = 0;newNode != NULL;i++, node = node->next, newNode = newNode->next)
            newNode->random = node->random == NULL ? NULL : nodeMap[node->random];
        return newList.next;
    }
};