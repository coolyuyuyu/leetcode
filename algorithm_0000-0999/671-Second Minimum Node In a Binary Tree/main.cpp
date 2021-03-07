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
    // find next greater
    int findSecondMinimumValue_Recursive(TreeNode* root, int val) {
        if (!root) {
            return -1;
        }

        if (root->val == val) {
            int val1 = findSecondMinimumValue_Recursive(root->left, val);
            int val2 = findSecondMinimumValue_Recursive(root->right, val);
            if (val1 != -1 && val2 != -1) {
                return min(val1, val2);
            }
            else {
                return (val1 == -1 ? val2 : val1);
            }
        }
        else {
            return root->val;
        }
    }

    // find next greater
    int findSecondMinimumValue_Iterative(TreeNode* root, int target) {
        assert(root);

        bool found = false;
        int minDifferentVal = -1;

        queue<TreeNode*> q({root});
        while (!q.empty()) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                root = q.front();
                q.pop();

                if (root->val != target) {
                    if (found) {
                        if (root->val < minDifferentVal) {
                            minDifferentVal = root->val;
                        }
                    }
                    else {
                        found = true;
                        minDifferentVal = root->val;
                    }
                }

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }

        return minDifferentVal;
    }

    int findSecondMinimumValue(TreeNode* root) {
        //return findSecondMinimumValue_Recursive(root, root->val);
        return findSecondMinimumValue_Iterative(root, root->val);
    }
};