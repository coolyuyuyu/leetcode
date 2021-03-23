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
    string findDuplicateSubtrees_Recursive(TreeNode* root, map<string, int>& counts, vector<TreeNode*>& duplicates) {
        if (!root) {
            return "#";
        }

        ostringstream oss;
        oss << root->val
            << "," << findDuplicateSubtrees_Recursive(root->left, counts, duplicates)
            << "," << findDuplicateSubtrees_Recursive(root->right, counts, duplicates);
        string id = oss.str();
        if (++counts[id] == 2) {
            duplicates.push_back(root);
        }

        return id;
    }
    void findDuplicateSubtrees_Iterative(TreeNode* root, map<string, int>& counts, vector<TreeNode*>& duplicates) {
        map<TreeNode*, string> m; // <tree, id>

        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                string id; {
                    ostringstream oss;
                    oss << node->val << "," << (node->left ? m[node->left] : "#") << "," << (node->right ? m[node->right] : "#");
                    id = oss.str();
                }

                m[node] = id;
                if (++counts[id] == 2) {
                    duplicates.push_back(node);
                }
            }
            else {
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

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> counts;
        vector<TreeNode*> duplicates;

        //findDuplicateSubtrees_Recursive(root, counts, duplicates);
        findDuplicateSubtrees_Iterative(root, counts, duplicates);

        return duplicates;
    }
};