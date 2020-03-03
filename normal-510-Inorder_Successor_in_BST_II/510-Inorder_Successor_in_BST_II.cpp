/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node *pNode = node;

        if(pNode->right != NULL)
        {
            pNode = pNode->right;
            while(pNode->left != NULL)
                pNode = pNode->left;
            return pNode;
        }

        pNode = node;
        while(pNode->parent != NULL)
        {
            if(pNode == pNode->parent->left)
                return pNode->parent;
            else
                pNode = pNode->parent;
        }
        return NULL;
    }
};