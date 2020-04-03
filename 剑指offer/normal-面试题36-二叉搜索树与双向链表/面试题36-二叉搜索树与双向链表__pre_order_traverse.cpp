/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    void constructTree(Node* root, Node **globalNode)
    {
        if(root == NULL)
            return;
        constructTree(root->left, globalNode);
        (*globalNode)->right = root;
        root->left = *globalNode;
        *globalNode = root;
        constructTree(root->right, globalNode);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        Node virtualNode(0);
        Node *globalNode;
        globalNode = &virtualNode;
        constructTree(root, &globalNode);
        globalNode->right = virtualNode.right;
        virtualNode.right->left = globalNode;
        return virtualNode.right;
    }
};