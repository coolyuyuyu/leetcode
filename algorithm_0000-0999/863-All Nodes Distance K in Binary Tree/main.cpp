/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> bfs(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> back;
        std::function<bool(TreeNode*)> collectBack = [&](TreeNode* root) {
            if (!root) { return false; }
            if (root == target) { return true; }

            if (collectBack(root->left)) {
                back[root->left] = root;
                return true;
            }
            else if (collectBack(root->right)) {
                back[root->right] = root;
                return true;
            }
            else {
                return false;
            }
        };
        collectBack(root);

        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(target, nullptr);
        for (int d = 0; !q.empty() && d < k; ++d) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, pre] = q.front();
                q.pop();

                if (cur->left && cur->left != pre) {
                    q.emplace(cur->left, cur);
                }
                if (cur->right && cur->right != pre) {
                    q.emplace(cur->right, cur);
                }
                if (back.find(cur) != back.end() && back[cur] != pre) {
                    q.emplace(back[cur], cur);
                }
            }
        }

        vector<int> ret;
        for (; !q.empty(); q.pop()) {
            const auto& [cur, _] = q.front();
            ret.push_back(cur->val);
        }

        return ret;
    }

    vector<int> dfs(TreeNode* root, TreeNode* target, int k) {
        vector<int> ret;
        std::function<void(TreeNode*, int)> fetch = [&](TreeNode* root, int k) {
            if (!root) { return; }
            if (k < 0) { return; }

            queue<TreeNode*> q;
            q.push(root);
            for(int i = 0; i < k; ++i) {
                for (int j = q.size(); 0 < j--;) {
                    auto node = q.front();
                    q.pop();

                    if (node->left) { q.push(node->left); }
                    if (node->right) { q.push(node->right); }
                }
            }

            for (; !q.empty(); q.pop()) {
                ret.push_back(q.front()->val);
            }
        };
        std::function<int(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return INT_MAX; }
            else if (root == target) {
                fetch(root, k);
                return 0;
            }

            int lftDepth = f(root->left);
            if (lftDepth != INT_MAX) {
                if (lftDepth == k - 1) {
                    ret.push_back(root->val);
                }
                else {
                    fetch(root->right, k - lftDepth - 2);
                }
                return lftDepth + 1;
            }

            int rhtDepth = f(root->right);
            if (rhtDepth != INT_MAX) {
                if (rhtDepth == k - 1) {
                    ret.push_back(root->val);
                }
                else {
                    fetch(root->left, k - rhtDepth - 2);
                }
                return rhtDepth + 1;
            }

            return INT_MAX;
        };
        f(root);

        return ret;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //return bfs(root, target, k);
        return dfs(root, target, k);
    }
};
