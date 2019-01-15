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
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* pRoot) {
        string str;

        stack<TreeNode*> stk;
        stk.push(pRoot);
        while (!stk.empty()) {
            TreeNode* pNode = stk.top();
            stk.pop();

            if (pNode) {
                str += to_string(pNode->val) + ",";
                stk.push(pNode->right);
                stk.push(pNode->left);
            }
            else {
                str += "#,";
            }
        }
        str.pop_back();

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* pRoot = nullptr;
        stack<TreeNode**> stk;
        stk.push(&pRoot);

        size_t pos = 0;
        while (pos < data.size()) {
            TreeNode** ppNode = stk.top();
            stk.pop();

            if (data[pos] == '#') {
                pos = pos + 2;
            }
            else {
                size_t found = data.find(',', pos);
                *ppNode = new TreeNode(atoi(data.substr(pos, found).c_str()));

                stk.push(&((*ppNode)->right));
                stk.push(&((*ppNode)->left));

                pos = found + 1;
            }
        }

        return pRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));