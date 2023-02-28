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
    int recursive(TreeNode* root, unordered_map<string, int>& key2id, unordered_map<int, int>& id2count, vector<TreeNode*>& duplicates) {
        if (!root) {
            return -1;
        }

        string key =
            std::to_string(root->val) +
            "#" +
            std::to_string(recursive(root->left, key2id, id2count, duplicates)) +
            "#" +
            std::to_string(recursive(root->right, key2id, id2count, duplicates));

        int id = key2id.emplace(key, key2id.size()).first->second;
        if (++id2count[id] == 2) {
            duplicates.push_back(root);
        }

        return id;
    }

    void iterative(TreeNode* root, unordered_map<string, int>& key2id, unordered_map<int, int>& id2count, vector<TreeNode*>& duplicates) {
        unordered_map<TreeNode*, int> tree2id;

        stack<pair<TreeNode*, bool>> stk({{root, false}}); // <tree, visited>
        while (!stk.empty()) {
            auto [root, visited] = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            if (visited) {
                string key =
                    std::to_string(root->val) +
                    "#" +
                    std::to_string(root->left ? tree2id[root->left] : -1) +
                    "#" +
                    std::to_string(root->right ? tree2id[root->right] : -1);

                int id = key2id.emplace(key, key2id.size()).first->second;
                if (++id2count[id] == 2) {
                    duplicates.push_back(root);
                }

                tree2id[root] = id;
            }
            else {
                stk.emplace(root, true);
                stk.emplace(root->left, false);
                stk.emplace(root->right, false);
            }
        }
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> key2id;
        unordered_map<int, int> id2count;
        vector<TreeNode*> duplicates;

        //recursive(root, key2id, id2count, duplicates);
        iterative(root, key2id, id2count, duplicates);

        return duplicates;
    }
};
