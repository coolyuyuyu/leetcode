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
    int bruteforce(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> parents;
        vector<TreeNode*> leave;
        std::function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* cur, TreeNode* pre) {
            if (!cur) { return; }

            parents[cur] = pre;
            if (cur->left == nullptr && cur->right == nullptr) {
                leave.push_back(cur);
            }

            dfs(cur->left, cur);
            dfs(cur->right, cur);
        };
        dfs(root, nullptr);

        std::function<bool(TreeNode*, const unordered_map<TreeNode*, int>&)> checkGood = [&](TreeNode* cur, const unordered_map<TreeNode*, int>& pre2dist) {
            for (int dist1 = 0; dist1 < distance && cur; ++dist1, cur = parents[cur]) {
                auto itr = pre2dist.find(cur);
                if (itr != pre2dist.end()) {
                    const auto& [_, dist2] = *itr;
                    return dist1 + dist2 <= distance;
                }
            }

            return false;
        };

        int ret = 0;
        for (int i = 0; i < leave.size(); ++i) {
            unordered_map<TreeNode*, int> pre2dist;
            int dist = 0;
            for (TreeNode* cur = leave[i]; cur && dist < distance; cur = parents[cur]) {
                pre2dist[cur] = dist++;
            }

            for (int j = i + 1; j < leave.size(); ++j) {
                if (checkGood(leave[j], pre2dist)) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    int btmup(TreeNode* root, int distance) {
        int ret = 0;
        std::function<std::array<int, 10>(TreeNode*)> dfs = [&](TreeNode* root) {
            std::array<int, 10> cnts = {};
            if (!root) {
                return cnts;
            }
            if (root->left == nullptr && root->right == nullptr) {
                cnts[0] = 1;
                return cnts;
            }

            auto lftCnts = dfs(root->left);
            auto rhtCnts = dfs(root->right);
            for (int i = 0; i < lftCnts.size() && i + 1 < distance; ++i) {
                for (int j = 0; j < rhtCnts.size() && i + j  + 2 <= distance; ++j) {
                    ret += lftCnts[i] * rhtCnts[j];
                }
            }

            for (int i = 1; i < cnts.size(); ++i) {
                cnts[i] = lftCnts[i - 1] + rhtCnts[i - 1];
            }

            return cnts;
        };
        dfs(root);

        return ret;
    }

    int countPairs(TreeNode* root, int distance) {
        //return bruteforce(root, distance);
        return btmup(root, distance);
    }
};
