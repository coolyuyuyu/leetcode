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
    void rightSideView_Recursive(TreeNode* root, int depth, vector<int>& nums) {
        if (!root) {
            return;
        }

        if (nums.size() <= depth) {
            nums.push_back(root->val);
        }

        rightSideView_Recursive(root->right, depth + 1, nums);
        rightSideView_Recursive(root->left, depth + 1, nums);
    }

    vector<int> rightSideView_Iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        vector<int> vals;
        while (!q.empty()) {
            vals.push_back(q.back()->val);

            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* parent = q.front();
                q.pop();

                if (parent->left) {
                    q.push(parent->left);
                }
                if (parent->right) {
                    q.push(parent->right);
                }
            }
        }

        return vals;
    }

    vector<int> rightSideView(TreeNode* root) {
        //vector<int> nums;
        //rightSideView_Recursive(root, 0, nums);
        //return nums;

        return rightSideView_Iterative(root);
    }
};