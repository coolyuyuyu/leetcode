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
    void smallestFromLeaf_Recursive(TreeNode* root, string& tmp, string& result) {
        if (!root) {
            return;
        }

        tmp.push_back('a' + root->val);

        if (!root->left && !root->right) {
            if (result.empty()) {
                result.insert(result.begin(), tmp.rbegin(), tmp.rend());
            }
            else {
                string rev(tmp.rbegin(), tmp.rend());
                if (rev < result) {
                    result = rev;
                }
            }
        }
        else {
            smallestFromLeaf_Recursive(root->left, tmp, result);
            smallestFromLeaf_Recursive(root->right, tmp, result);
        }

        tmp.pop_back();
    }

    void smallestFromLeaf_Iterative(TreeNode* root, string& tmp, string& result) {
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
                        result.insert(result.begin(), tmp.rbegin(), tmp.rend());
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
    }

    string smallestFromLeaf(TreeNode* root) {
        string tmp;
        string result;

        //smallestFromLeaf_Recursive(root, tmp, result);
        smallestFromLeaf_Iterative(root, tmp, result);

        return result;
    }
};