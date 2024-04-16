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
    TreeNode* recursive(TreeNode* root, int val, int depth) {
        std::function<void(TreeNode**, int, bool)> f = [&](TreeNode** ppNode, int depth, bool addLft) {
            if (depth == 1) {
                if (addLft) {
                    *ppNode = new TreeNode(val, *ppNode, nullptr);
                }
                else {
                    *ppNode = new TreeNode(val, nullptr, *ppNode);
                }
            }
            else if (*ppNode){
                f(&((*ppNode)->left), depth - 1, true);
                f(&((*ppNode)->right), depth - 1, false);
            }
        };
        f(&root, depth, true);

        return root;
    }

    TreeNode* iterative(TreeNode* root, int val, int depth) {
        queue<pair<TreeNode**, bool>> q({{&root, true}});
        for (; !q.empty() && depth > 1; --depth) {
            for (int i = q.size(); 0 < i--;) {
                auto [ppNode, addLft] = q.front();
                q.pop();

                if (*ppNode) {
                    q.emplace(&((*ppNode)->left), true);
                    q.emplace(&((*ppNode)->right), false);
                }
            }
        }

        while (!q.empty()) {
            auto [ppNode, addLft] = q.front();
            q.pop();

            if (addLft) {
                *ppNode = new TreeNode(val, *ppNode, nullptr);
            }
            else {
                *ppNode = new TreeNode(val, nullptr, *ppNode);
            }
        }

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //return recursive(root, val, depth);
        return iterative(root, val, depth);
    }
};
