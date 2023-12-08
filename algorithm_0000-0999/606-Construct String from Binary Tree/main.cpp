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
    string recursive(TreeNode* root) {
        ostringstream oss;
        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            oss << root->val;
            if (root->left == nullptr && root->right == nullptr) {
                return;
            }

            oss << '(';
            if(root->left) {
                f(root->left);
            }
            oss << ')';

            if(root->right) {
                oss << '(';
                f(root->right);
                oss << ')';
            }
        };
        f(root);

        return oss.str();
    }

    string iterative(TreeNode* root) {
        ostringstream oss;
        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (visited) {
                oss << ")";
            }
            else {
                oss << "(";
                oss << node->val;

                stk.emplace(node, true);
                if (node->right) {
                    if (!node->left) {
                        oss << "()";
                    }
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        string ret = oss.str();
        return ret.substr(1, ret.size() - 2);
    }

    string tree2str(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
