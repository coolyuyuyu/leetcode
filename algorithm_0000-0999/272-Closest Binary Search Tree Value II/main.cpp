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
    template<class T>
    void dfs(TreeNode* root, double target, int k, T& pq) {
        if (!root) {
            return;
        }

        double distance = fabs(target - root->val);
        if (pq.size() < k) {
            pq.emplace(distance, root->val);
        }
        else {
            if (distance < pq.top().first) {
                pq.pop();
                pq.emplace(distance, root->val);
            }
        }

        dfs(root->left, target, k, pq);
        dfs(root->right, target, k, pq);
    }

    template<class T>
    void inorder(TreeNode* root, double target, int k, T& pq) {
        if (!root) {
            return;
        }

        inorder(root->left, target, k, pq);

        double distance = fabs(target - root->val);
        if (pq.size() < k) {
            pq.emplace(distance, root->val);
        }
        else {
            if (distance < pq.top().first) {
                pq.pop();
                pq.emplace(distance, root->val);
            }
            else {
                return;
            }
        }

        inorder(root->right, target, k, pq);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        auto comp = [](const pair<double, int>& lft, const pair<double, int>& rht) {
            return lft.first < rht.first;
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(comp)> pq(comp);

        //dfs(root, target, k, pq);
        inorder(root, target, k, pq);

        vector<int> nums(pq.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[i] = pq.top().second;
            pq.pop();
        }
        return nums;
    }
};