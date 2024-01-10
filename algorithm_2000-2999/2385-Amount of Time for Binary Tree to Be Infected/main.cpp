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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> backs;
        TreeNode* src = nullptr;
        std::function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* cur, TreeNode* pre) {
            if (cur == nullptr) { return false; }
            if (cur->val == start) {
                src = cur;
                if (pre) {
                backs[cur] = pre; }
                return true;
            }

            if (dfs(cur->left, cur) || dfs(cur->right, cur)) {
                if (pre) {
                backs[cur] = pre;
                }
                return true;
            }
            return false;
        };
        dfs(root, nullptr);

        int ret = -1;
        for (queue<pair<TreeNode*, TreeNode*>> q({{src, nullptr}}); !q.empty(); ++ret) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, pre] = q.front();
                q.pop();

                if (cur->left && cur->left != pre) {
                    q.emplace(cur->left, cur);
                }
                if (cur->right && cur->right != pre) {
                    q.emplace(cur->right, cur);
                }
                if (backs.find(cur) != backs.end() && backs[cur] != pre) {
                    q.emplace(backs[cur], cur);
                }
            }
        }

        return ret;
    }
};
