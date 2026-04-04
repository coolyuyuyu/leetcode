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
    int maxSum(TreeNode* root) {
        vector<TreeNode*> nodes;
        unordered_map<TreeNode*, TreeNode*> parents;
        std::function<void(TreeNode*, TreeNode*)> f1 = [&](TreeNode* cur, TreeNode* pre) {
            if (cur) {
                nodes.push_back(cur);
                parents[cur] = pre;
                f1(cur->left, cur);
                f1(cur->right, cur);
            }
        };
        f1(root, nullptr);

        int ret = INT_MIN;
        std::function<void(TreeNode*, int, bitset<2001>&)> f2 = [&](TreeNode* cur, int sum, bitset<2001>& seen) {
            if (!cur || seen[cur->val + 1000]) {
                return;
            }

            sum += cur->val;
            seen[(cur->val) + 1000] = true;;

            ret = std::max(ret, sum);

            f2(cur->left, sum, seen);
            f2(cur->right, sum, seen);
            f2(parents[cur], sum, seen);

            sum -= cur->val;
            seen[cur->val + 1000] = false;
        };
        for (auto& node : nodes) {
            bitset<2001> seen;
            f2(node, 0, seen);
        }


        return ret;
    }
};
