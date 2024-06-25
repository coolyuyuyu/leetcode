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
    TreeNode* recursive(TreeNode* root) {
        int sum = 0;
        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return; }

            f(root->right);

            int val = root->val;
            root->val += sum;
            sum += val;

            f(root->left);
        };
        f(root);

        return root;
    }

    TreeNode* iterative(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stk({{root, false}});

        for (int sum = 0; !stk.empty();) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (!node) { continue; }

            if (visited) {
                int val = node->val;
                node->val += sum;
                sum += val;
            }
            else {
                stk.emplace(node->left, false);
                stk.emplace(node, true);
                stk.emplace(node->right, false);
            }
        }

        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
