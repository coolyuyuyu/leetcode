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
    int greedy(TreeNode* root) {
        int cnt = 0;
        unordered_set<TreeNode*> covered({nullptr});
        std::function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* parent) {
            if (!node) { return; }

            dfs(node->left, node);
            dfs(node->right, node);
            if ((covered.find(node->left) == covered.end()) ||
                (covered.find(node->right) == covered.end()) ||
                (parent == nullptr && covered.find(node) == covered.end())
            ) {
                ++cnt;
                covered.insert(parent);
                covered.insert(node);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        };
        dfs(root, nullptr);

        return cnt;
    }

    int dp1(TreeNode* root) {
        int cnt = 0;

        // dp state
        // 0: not covered
        // 1: covered without camera camera
        // 2: covered with camera
        std::function<int(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* parent) {
            if (!node) { return 1; }

            int stateL = dfs(node->left, node);
            int stateR = dfs(node->right, node);
            if (stateL == 0 || stateR == 0) {
                ++cnt;
                return 2;
            }
            else if (stateL == 1 && stateR == 1) {
                if (parent == nullptr) {
                    ++cnt;
                    return 2;
                }
                else {
                    return 0;
                }
            }
            else {
                return 1;
            }
        };
        dfs(root, nullptr);

        return cnt;
    }

    int dp2(TreeNode* root) {
        // dp[node][1st]: the number of cameras in tree rooted at node, and the node is not covered
        // dp[node][2nd]: the number of cameras in tree rooted at node, and the node is corvered without camera
        // dp[node][3rd]: the number of cameras in tree rooted at node, and the node is corvered with camera
        std::function<tuple<int, int, int>(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* parent) -> tuple<int, int, int> {
            if (!node) { return {0, 0, 1001}; }

            auto [l1, l2, l3] = dfs(node->left, node);
            auto [r1, r2, r3] = dfs(node->right, node);
            int s1 = l2 + r2;
            int s2 = std::min(l3 + std::min(r2, r3), std::min(l2, l3) + r3);
            int s3 = std::min({l1, l2, l3}) + 1 + std::min({r1, r2, r3});

            return {s1, s2, s3};
        };
        auto [s1, s2, s3] = dfs(root, nullptr);

        return std::min(s2, s3);
    }

    int minCameraCover(TreeNode* root) {
        //return greedy(root);
        //return dp1(root);
        return dp2(root);
    }
};
