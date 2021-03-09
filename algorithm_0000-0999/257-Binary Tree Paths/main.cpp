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
    void binaryTreePaths_Recursive(TreeNode* root, vector<int>& vals, vector<string>& results) {
        if (!root) {
            return;
        }

        vals.push_back(root->val);
        if (!root->left && !root->right) {
            ostringstream oss;
            oss << vals.front();
            for (size_t i = 1; i < vals.size(); ++i) {
                oss << "->" << vals[i];
            }
            results.push_back(oss.str());
        }
        else {
            binaryTreePaths_Recursive(root->left, vals, results);
            binaryTreePaths_Recursive(root->right, vals, results);
        }
        vals.pop_back();
    }

    vector<string> binaryTreePaths_Iterative(TreeNode* root) {
        vector<int> vals;
        vector<string> results;

        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, true);
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                vals.push_back(node->val);
                if (!node->left && !node->right) {
                    ostringstream oss;
                    oss << vals.front();
                    for (size_t i = 1; i < vals.size(); ++i) {
                        oss << "->" << vals[i];
                    }
                    results.push_back(oss.str());
                }

                stk.emplace(node, false);

                if (node->right) {
                    stk.emplace(node->right, true);
                }
                if (node->left) {
                    stk.emplace(node->left, true);
                }
            }
            else {
                vals.pop_back();
            }
        }

        return results;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        //vector<int> vals;
        //vector<string> results;
        //binaryTreePaths_Recursive(root, vals, results);
        //return results;

        return binaryTreePaths_Iterative(root);
    }
};