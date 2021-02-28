/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        struct Item {
            Item(TreeNode* pNode, const string& str)
                : m_pNode(pNode)
                , m_str(str)
            {}
            TreeNode* m_pNode;
            string m_str;
        };
        stack<Item> stk;
        if (root) {
            stk.push(Item(root, ""));
        }

        vector<string> paths;
        while (!stk.empty()) {
            Item item = stk.top();
            stk.pop();

            TreeNode* pNode = item.m_pNode;
            string path = item.m_str;
            if (!path.empty()) {
                path.append("->");
            }
            path.append(to_string(pNode->val));

            bool end = true;
            if (pNode->left) {
                end = false;
                stk.push(Item(pNode->left, path));
            }
            if (pNode->right) {
                end = false;
                stk.push(Item(pNode->right, path));
            }
            if (end) {
                paths.push_back(path);
            }
        }

        return paths;
    }
};