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
class Solution {
public:
    vector<int> recursive(TreeNode* root) {
        vector<int> ret;
        std::function<void(TreeNode*, int)> f = [&](TreeNode* root, int depth) {
            if (!root) { return; }

            while (depth >= ret.size()) {
                ret.push_back(INT_MIN);
            }
            ret[depth] = std::max(ret[depth], root->val);

            f(root->left, depth + 1);
            f(root->right, depth + 1);
        };
        f(root, 0);

        return ret;
    }

    vector<int> iterative(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if (root) { q.push(root); }
        while (!q.empty()) {
            int val = INT_MIN;
            for (int i = q.size(); 0 < i--;) {
                TreeNode* node = q.front();
                q.pop();

                val = std::max(val, node->val);

                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            ret.push_back(val);
        }
        return ret;
    }

    vector<int> largestValues(TreeNode* root) {
        return recursive(root);
        //return iterative(root);
    }
};
