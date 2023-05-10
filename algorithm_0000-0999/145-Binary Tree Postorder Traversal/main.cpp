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
    void recursive(TreeNode* root, vector<int>& nums) {
        if (!root) {
            return;
        }

        recursive(root->left, nums);
        recursive(root->right, nums);
        nums.push_back(root->val);
    }

    vector<int> recursive(TreeNode* root) {
        vector<int> nums;
        recursive(root, nums);
        return nums;
    }

    vector<int> iterative1(TreeNode* root) {
        vector<int> nums;
        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [root, visited] = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            if (visited) {
                nums.push_back(root->val);
            }
            else {
                stk.emplace(root, true);
                stk.emplace(root->right, false);
                stk.emplace(root->left, false);
            }
        }

        return nums;
    }

    vector<int> iterative2(TreeNode* root) {
        vector<int> nums;
        for (stack<TreeNode*> stk({root}); !stk.empty();) {
            root = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            nums.push_back(root->val);
            stk.push(root->left);
            stk.push(root->right);
        }
        std::reverse(nums.begin(), nums.end());

        return nums;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        //return recursive(root);
        //return iterative1(root);
        return iterative2(root);
    }
};
