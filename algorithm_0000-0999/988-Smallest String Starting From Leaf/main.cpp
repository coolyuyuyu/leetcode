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
        string ret, cur;
        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return; }

            cur.push_back('a' + root->val);
            if (!root->left && !root->right) {
                if (ret.empty() || std::lexicographical_compare(cur.rbegin(), cur.rend(), ret.rbegin(), ret.rend())) {
                    ret = cur;
                }
            }
            f(root->left);
            f(root->right);
            cur.pop_back();
        };
        f(root);
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    string iterative(TreeNode* root) {
        string tmp, result;

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk; // <node, visited>
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (!node->left && !node->right) {
                    if (result.empty()) {
                        result.append(tmp.rbegin(), tmp.rend());
                    }
                    else {
                        string rev(tmp.rbegin(), tmp.rend());
                        if (rev < result) {
                            result = rev;
                        }
                    }
                }

                tmp.pop_back();
            }
            else {
                tmp.push_back('a' + node->val);

                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return result;
    }

    string smallestFromLeaf(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
