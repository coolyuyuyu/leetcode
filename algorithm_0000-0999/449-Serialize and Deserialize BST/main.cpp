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
    string serialize(TreeNode* root) {
        ostringstream oss;

        bool first = true;
        stack<TreeNode*> stk;
        if (root) {
            stk.emplace(root);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (0 < oss.tellp()) {
                oss << " ";
            }
            oss << node->val;

            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }

        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* pHead = nullptr;
        TreeNode** ppCur = &pHead;

        int num;
        stack<TreeNode*> stk;
        for (istringstream iss(data); iss >> num;) {
            while (!stk.empty() && stk.top()->val < num) {
                ppCur = &(stk.top()->right);
                stk.pop();
            }

            *ppCur = new TreeNode(num);
            stk.push(*ppCur);

            ppCur = &((*ppCur)->left);
        }

        return pHead;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;