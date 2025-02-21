/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root):
        m_root(root) {
        queue<pair<TreeNode*, int>> q({{m_root, 0}});
        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();

            if (!node) { continue; }

            node->val = val;

            q.emplace(node->left, val * 2 + 1);
            q.emplace(node->right, val * 2 + 2);
        }
    }

    bool find(int target) {
        stack<bool> stk;
        for (; target; target = (target - 1) / 2) {
            stk.push(!(target & 1));
        }

        TreeNode* node = m_root;
        while (node && !stk.empty()) {
            bool dir = stk.top();
            stk.pop();

            node = dir ? node->right : node->left;
        }

        return node && stk.empty();
    }

private:
    TreeNode* m_root;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
