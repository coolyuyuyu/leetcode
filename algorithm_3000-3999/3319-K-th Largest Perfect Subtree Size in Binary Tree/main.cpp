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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        std::function<pair<int, bool>(TreeNode*)> dfs = [&](TreeNode* root) -> pair<int, bool> {
            if (!root) {
                return {0, true};
            }

            auto [lftCnt, lftPerfect] = dfs(root->left);
            auto [rhtCnt, rhtPerfect] = dfs(root->right);
            bool perfect = lftCnt == rhtCnt && lftPerfect && rhtPerfect;
            if (perfect) {
                pq.push(lftCnt * 2 + 1);
                if (pq.size() > k) {
                    pq.pop();
                }
            }

            return {lftCnt + rhtCnt + 1, perfect};
        };
        dfs(root);

        return pq.size() >= k ? pq.top() : -1;
    }
};
