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
    bool isSamePath_dfsRecv(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }

        return head->val == root->val && (isSamePath_dfsRecv(head->next, root->left) || isSamePath_dfsRecv(head->next, root->right));
    }

    // Time: O(MN)
    bool isSubPath_dfsRecv(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }


        if (isSamePath_dfsRecv(head, root)) {
            return true;
        }
        else {
            return isSubPath_dfsRecv(head, root->left) || isSubPath_dfsRecv(head, root->right);
        }
    }

    bool isSamePath_dfsIter(ListNode* head, TreeNode* root) {
        assert(head && root);

        stack<pair<ListNode*, TreeNode*>> stk({{head, root}});
        while (!stk.empty()) {
            auto [head, root] = stk.top();
            stk.pop();

            if (!head) {
                return true;
            }
            if (!root || head->val != root->val) {
                continue;
            }

            stk.emplace(head->next, root->right);
            stk.emplace(head->next, root->left);
        }

        return false;
    }

    // Time: O(MN)
    bool isSubPath_dfsIter(ListNode* head, TreeNode* root) {
        assert(head && root);

        stack<TreeNode*> stk({root});
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }
            if (isSamePath_dfsIter(head, root)) {
                return true;
            }

            stk.push(root->right);
            stk.push(root->left);
        }

        return false;
    }

    bool isSubPath_dfsKMP(TreeNode* root, const vector<int>& nums, const vector<size_t>& suffix, int dp) {
        if (!root) {
            return false;
        }

        size_t j = dp;
        while (0 < j && nums[j] != root->val) {
            j = suffix[j - 1];
        }
        dp = j + (nums[j] == root->val ? 1 : 0);

        if (dp == nums.size()) {
            return true;
        }

        return isSubPath_dfsKMP(root->left, nums, suffix, dp) || isSubPath_dfsKMP(root->right, nums, suffix, dp);
    }

    // Time: O(M+N)
    bool isSubPath_kmp(ListNode* head, TreeNode* root) {
        assert(head && root);

        vector<int> nums;
        for (; head; head = head->next) {
            nums.push_back(head->val);
        }

        vector<size_t> suffix(nums.size());
        suffix[0] = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            size_t j = suffix[i - 1];
            while (0 < j && nums[j] != nums[i]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (nums[j] == nums[i] ? 1 : 0);
        }

        int dp = (nums[0] == root->val ? 1 : 0);
        if (dp == 1 && nums.size() == 1) {
            return true;
        }
        return isSubPath_dfsKMP(root->left, nums, suffix, dp) || isSubPath_dfsKMP(root->right, nums, suffix, dp);;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        //return isSubPath_dfsRecv(head, root);
        //return isSubPath_dfsIter(head, root);
        return isSubPath_kmp(head, root);
    }
};
