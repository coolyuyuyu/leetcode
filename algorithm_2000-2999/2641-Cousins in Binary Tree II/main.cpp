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
    TreeNode* replaceValueInTree(TreeNode* root) {
        for (queue<pair<TreeNode*, int>> q({{root, 0}}); !q.empty();) {
            int sum = 0;
            unordered_map<int, pair<int, TreeNode*>> id2valnode;
            for (int i = q.size(); 0 < i--;) {
                auto [node, id] = q.front();
                q.pop();

                sum += node->val;
                id2valnode[id] = {node->val, node};

                if (node->left) { q.emplace(node->left, i * 2 + 1); }
                if (node->right) { q.emplace(node->right, i * 2 + 2); }
            }

            for (auto& [id, valnode] : id2valnode) {
                auto& [val, node] = valnode;
                int newval = sum - val;
                if (id & 1) {
                    newval -= id2valnode.find(id + 1) != id2valnode.end() ? id2valnode[id + 1].first : 0;
                }
                else {
                    newval -= id2valnode.find(id - 1) != id2valnode.end() ? id2valnode[id - 1].first: 0;
                }
                node->val = newval;
            }
        }

        return root;
    }
};
