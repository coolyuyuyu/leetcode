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
        unordered_map<TreeNode*, TreeNode*> backs;
        std::function<bool(TreeNode*, TreeNode*)> collectBacks = [&](TreeNode* root, TreeNode* target) {
            if (!root) {
                return false;
            }
            if (root == target) {
                return true;
            }

            if (collectBacks(root->left, target)) {
                backs[root->left] = root;
                return true;
            }
            else if (collectBacks(root->right, target)) {
                backs[root->right] = root;
                return true;
            }
            else {
                return false;
            }
        };
        collectBacks(root, target);

        queue<pair<TreeNode*, TreeNode*>> q({{target, nullptr}});
        for (; !q.empty() && 0 < k; --k) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, pre] = q.front();
                q.pop();

                if (cur->left && cur->left != pre) {
                    q.emplace(cur->left, cur);
                }
                if (cur->right && cur->right != pre) {
                    q.emplace(cur->right, cur);
                }
                if (backs[cur] && backs[cur] != pre) {
                    q.emplace(backs[cur], cur);
                }
            }
        }

        vector<int> ret(q.size());
        for (int i = q.size(); 0 < i--; q.pop()) {
            ret[i] = q.front().first->val;
        }

        return ret;
    }

    vector<int> dfs(TreeNode* root, TreeNode* target, int k) {
        vector<int> ret;

        std::function<void(TreeNode*, int)> fetch = [&](TreeNode* root, int k) {
            if (!root) {
                return;
            }

            if (k == 0) {
                ret.push_back(root->val);
            }
            else {
                fetch(root->left, k - 1);
                fetch(root->right, k - 1);
            }
        };

        std::function<int(TreeNode*, TreeNode*, int)> f = [&](TreeNode* root, TreeNode* target, int k) {
            if (!root) {
                return -1;
            }

            if (root == target) {
                fetch(target, k);
                return 0;
            }

            int lftDepth = f(root->left, target, k);
            if (0 <= lftDepth) {
                if (lftDepth + 1 == k) {
                    ret.push_back(root->val);
                }
                else if ((lftDepth + 2) <= k) {
                    fetch(root->right, k - lftDepth - 2);
                }
                return lftDepth + 1;
            }

            int rhtDepth = f(root->right, target, k);
            if (0 <= rhtDepth) {
                if (rhtDepth + 1 == k) {
                    ret.push_back(root->val);
                }
                else if ((rhtDepth + 2) <= k) {
                    fetch(root->left, k - rhtDepth - 2);
                }
                return rhtDepth + 1;
            }

            return -1;
        };
        f(root, target, k);

        return ret;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //return bfs(root, target, k);
        return dfs(root, target, k);
    }
};
