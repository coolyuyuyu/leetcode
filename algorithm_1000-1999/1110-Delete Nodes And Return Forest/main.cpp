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
    vector<TreeNode*> iterative(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> targets(to_delete.begin(), to_delete.end());

        vector<TreeNode*> ret;
        for (queue<pair<TreeNode**, bool>> q({{&root, true}}); !q.empty();) {
            auto [ppNode, isRoot] = q.front();
            q.pop();

            if (*ppNode == nullptr) { continue; }

            bool toRemove = (targets.find((*ppNode)->val) != targets.end());
            q.emplace(&((*ppNode)->left), toRemove);
            q.emplace(&((*ppNode)->right), toRemove);

            if (isRoot && !toRemove) {
                ret.push_back(*ppNode);
            }
            if (toRemove) {
                *ppNode = nullptr;
            }
        }

        return ret;
    }

    vector<TreeNode*> recursive(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> targets(to_delete.begin(), to_delete.end());

        vector<TreeNode*> ret;
        std::function<TreeNode*(TreeNode*, bool)> f = [&](TreeNode* root, bool isRoot) -> TreeNode* {
            if (!root) { return nullptr; }

            bool toRemove = (targets.find(root->val) != targets.end());
            if (isRoot && !toRemove) {
                ret.push_back(root);
            }
            root->left = f(root->left, toRemove);
            root->right = f(root->right, toRemove);

            return toRemove ? nullptr : root;
        };
        f(root, true);

        return ret;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //return iterative(root, to_delete);
        return recursive(root, to_delete);
    }
};
