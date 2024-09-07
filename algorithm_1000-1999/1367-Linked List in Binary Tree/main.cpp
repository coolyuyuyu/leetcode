/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Time: O(M * N)
    bool byDfsRecv(ListNode* head, TreeNode* root) {
        std::function<bool(ListNode*, TreeNode*)> isSamePath = [&](ListNode* head, TreeNode* root) {
            if (!head) { return true; }
            if (!root) { return false; }

            return (head->val == root->val) && (isSamePath(head->next, root->left) || isSamePath(head->next, root->right));
        };

        std::function<bool(ListNode*, TreeNode*)> isSubPath = [&](ListNode* head, TreeNode* root) {
            if (!head) { return true; }
            if (!root) { return false; }

            return isSamePath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
        };

        return isSubPath(head, root);
    }

    // Time: O(M * N)
    bool byDfsIter(ListNode* head, TreeNode* root) {
        std::function<bool(ListNode*, TreeNode*)> isSamePath = [&](ListNode* head, TreeNode* root) {
            queue<pair<ListNode*, TreeNode*>> q({{head, root}});
            for (queue<pair<ListNode*, TreeNode*>> q({{head, root}}); !q.empty();) {
                auto [head, root] = q.front();
                q.pop();

                if (!head) { return true; }
                if (!root || head->val != root->val) { continue; }

                q.emplace(head->next, root->left);
                q.emplace(head->next, root->right);
            }
            return false;
        };


        for (queue<TreeNode*> q({root}); !q.empty();) {
            auto root = q.front();
            q.pop();

            if (!root) { continue; }
            if (isSamePath(head, root)) { return true; }

            q.push(root->left);
            q.push(root->right);
        }

        return false;
    }

    // Time: O(M + N)
    bool byDfsKmp(ListNode* head, TreeNode* root) {
        vector<int> nums;
        for (; head; head = head->next) {
            nums.push_back(head->val);
        }

        int n = nums.size();
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && nums[j] != nums[i]) {
                j = lps [j - 1];
            }
            lps[i] = j + (nums[j] == nums[i] ? 1 : 0);
        }

        std::function<bool(TreeNode*, int)> dfs = [&](TreeNode* root, int dp) {
            if (!root) { return false; }

            int j = dp;
            while (0 < j && root->val != nums[j]) {
                j = lps[j - 1];
            }
            dp = j + (root->val == nums[j] ? 1 : 0);

            if (dp >= n) { return true; }

            return dfs(root->left, dp) || dfs(root->right, dp);
        };

        return dfs(root, 0);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        //return byDfsRecv(head, root);
        //return byDfsIter(head, root);
        return byDfsKmp(head, root);
    }
};
