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
        vector<int> nums;
        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return; }
            f(root->left);
            nums.push_back(root->val);
            f(root->right);
        };
        f(root);

        return nums;
    }

    vector<int> iterative1(TreeNode* root) {
        vector<int> nums;
        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (!node) { continue; }

            if (visited) {
                nums.push_back(node->val);
            }
            else {
                stk.emplace(node->right, false);
                stk.emplace(node, true);
                stk.emplace(node->left, false);
            }
        }

        return nums;
    }

    vector<int> iterative2(TreeNode* root) {
        vector<int> nums;
        for (stack<TreeNode*> stk; root || !stk.empty();) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            if (!stk.empty()) {
                root = stk.top();
                stk.pop();

                nums.push_back(root->val);

                root = root->right;
            }
        }

        return nums;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //return recursive(root);
        //return iterative1(root);
        return iterative2(root);
    }
};
