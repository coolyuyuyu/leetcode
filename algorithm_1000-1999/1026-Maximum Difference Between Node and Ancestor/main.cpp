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
    int recursive(TreeNode* root, int minVal, int maxVal) {
        if (!root) {
            return 0;
        }

        int maxDiff = std::max(abs(root->val - minVal), abs(root->val - maxVal));
        minVal = std::min(minVal, root->val);
        maxVal = std::max(maxVal, root->val);
        int lftMaxDiff = recursive(root->left, minVal, maxVal);
        int rhtMaxDiff = recursive(root->right, minVal, maxVal);

        return std::max({maxDiff, lftMaxDiff, rhtMaxDiff});
    }

    int iterative(TreeNode* root) {
        assert(root);

        queue<tuple<TreeNode*, int, int>> q;
        q.emplace(root, root->val, root->val);

        int ret = 0;
        while (!q.empty()) {
            root = std::get<0>(q.front());
            int minVal = std::get<1>(q.front());
            int maxVal = std::get<2>(q.front());
            q.pop();

            ret = std::max({ret, abs(root->val - minVal), abs(root->val - maxVal)});
            minVal = std::min(minVal, root->val);
            maxVal = std::max(maxVal, root->val);
            if (root->left) {
                q.emplace(root->left, minVal, maxVal);
            }
            if (root->right) {
                q.emplace(root->right, minVal, maxVal);
            }
        }

        return ret;
    }

    int maxAncestorDiff(TreeNode* root) {
        assert(root);

        //return recursive(root, root->val, root->val);
        return iterative(root);
    }
};
