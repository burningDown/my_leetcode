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
	void constructList(Node *root, Node **pStart, Node **pEnd)
	{
		*pStart = NULL;
		*pEnd = NULL;
		if (root == NULL)
			return;

		Node *lStart, *lEnd, *rStart, *rEnd;
		constructList(root->left, &lStart, &lEnd);
		constructList(root->right, &rStart, &rEnd);

		if (lEnd != NULL)
		{
			lEnd->right = root;
			root->left = lEnd;
		}
		else
			root->left = NULL;

		if (rStart != NULL)
		{
			root->right = rStart;
			rStart->left = root;
		}
		else
			root->right = NULL;

		*pStart = lStart == NULL ? root : lStart;
		*pEnd = rEnd == NULL ? root : rEnd;
	}
public:
	Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
		Node *head, *end;
		constructList(root, &head, &end);
        end->right = head;
        head->left = end;
		return head;
	}
};