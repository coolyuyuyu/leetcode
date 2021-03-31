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
    FindElements(TreeNode* root)
        : m_root(root) {
        queue<TreeNode*> q;
        if (m_root) {
            m_root->val = 0;
            q.push(m_root);
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                node->left->val = node->val * 2 + 1;
                q.push(node->left);
            }
            if (node->right) {
                node->right->val = node->val * 2 + 2;
                q.push(node->right);
            }
        }
    }

    bool find(int target) {
        stack<bool> directions; // true: left, false: right
        while (0 < target) {
            if (target % 2 == 1) {
                directions.push(true);
                target /= 2;
            }
            else {
                directions.push(false);
                target = target / 2 - 1;
            }
        }

        TreeNode* node = m_root;
        while (node && !directions.empty()) {
            bool direction = directions.top();
            directions.pop();

            if (direction) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }

        return (node && directions.empty());
    }

private:
    TreeNode* m_root;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */