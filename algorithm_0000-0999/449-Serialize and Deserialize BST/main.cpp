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
        stk.emplace(pRoot);
        while (!stk.empty()) {
            TreeNode* pNode = stk.top();
            stk.pop();

            if (pNode) {
                str += to_string(pNode->val) + " ";
                stk.emplace(pNode->right);
                stk.emplace(pNode->left);
            }
        }

        if (!str.empty()) {
            str.pop_back();
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* pRoot = nullptr;
        stack<pair<TreeNode**, pair<int, int>>> stk;
        stk.emplace(&pRoot, pair<int, int>(INT_MIN, INT_MAX));

        istringstream iss(data);
        int num;
        while (iss >> num) {
            while (num < stk.top().second.first ||  stk.top().second.second < num) {
                stk.pop();
            }
            TreeNode** ppNode = stk.top().first;
            pair<int, int> range = stk.top().second;

            stk.pop();

            *ppNode = new TreeNode(num);
            stk.emplace(&((*ppNode)->right), pair<int, int>(num, range.second));
            stk.emplace(&((*ppNode)->left), pair<int, int>(range.first, num));
        }

        return pRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));