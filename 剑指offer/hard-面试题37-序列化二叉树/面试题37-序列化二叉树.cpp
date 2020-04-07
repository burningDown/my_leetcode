/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 private:
	 void parseNodeByIdx(const string &data, int start, int *end, bool *isNull, bool *isEnd)
	 {
		 int idx = start;
		 while (true)
		 {
			 if (data[idx] >= '0' && data[idx] <= '9' || data[idx] == '-')
			 {
				 *isNull = false;
				 idx++;
			 }
			 else if (data[idx] >= 'l' && data[idx] <= 'u')
			 {
				 *isNull = true;
				 idx++;
			 }
			 else if (data[idx] == ']')
			 {
				 *isEnd = true;
				 break;
			 }
			 else
				 break;
		 }
		 *end = idx;
	 }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> stateQueue;
        TreeNode *node;

        result.reserve(200);
        result += '[';

        if(root == NULL)
            result += "null";
        else
        {
            result += to_string(root->val);
            stateQueue.push(root->left);
            stateQueue.push(root->right);
        }

        while(!stateQueue.empty())
        {
            node = stateQueue.front();
            stateQueue.pop();

            if(node == NULL)
                result += ",null";
            else
            {
                result += ',';
                result += to_string(node->val);
                stateQueue.push(node->left);
                stateQueue.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() <= 2)
            return NULL;
        
        TreeNode *root, *node;
        queue<TreeNode*> stateQueue;

        int start = 1, end = 1;
        bool isNull = false, isEnd = false;
        int idx = 0;

        parseNodeByIdx(data, start, &end, &isNull, &isEnd);

        if(!isNull)
        {
            root = new TreeNode(atoi(data.substr(start, end - start).c_str()));
            stateQueue.push(root);
        }
        else
            root = NULL;
        idx++;
        start = end + 1;

        while(!stateQueue.empty())
        {
            node = stateQueue.front();
            stateQueue.pop();

            parseNodeByIdx(data, start, &end, &isNull, &isEnd);
            if(!isNull)
            {
                node->left = new TreeNode(atoi(data.substr(start, end - start).c_str()));
                stateQueue.push(node->left);
            }
            else
                node->left = NULL;
            idx++;
            start = end + 1;

            if(isEnd)
                break;

            parseNodeByIdx(data, start, &end, &isNull, &isEnd);
            if(!isNull)
            {
                node->right = new TreeNode(atoi(data.substr(start, end - start).c_str()));
                stateQueue.push(node->right);
            }
            else
                node->right = NULL;
            idx++;
            start = end + 1;

            if(isEnd)
                break;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));