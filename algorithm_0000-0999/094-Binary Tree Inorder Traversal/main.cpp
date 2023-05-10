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
        nums.push_back(root->val);
        recursive(root->right, nums);
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
                stk.emplace(root->right, false);
                stk.emplace(root, true);
                stk.emplace(root->left, false);
            }
        }

        return nums;
    }

    vector<int> iterative2(TreeNode* root) {
        vector<int> nums;
        for (stack<TreeNode*> stk; root || !stk.empty();) {
            if (root) {
                while (root) {
                    stk.push(root);
                    root = root->left;
                }
            }
            else {
                root = stk.top();
                stk.pop();

                nums.push_back(root->val);
                root = root->right;
            }
        }

        return nums;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //return recursive(root);
        //return iterative1(root);
        return iterative2(root);
    }
};

