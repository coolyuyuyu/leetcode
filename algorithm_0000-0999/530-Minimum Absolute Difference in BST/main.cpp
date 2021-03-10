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
    void getMinimumDifference_Recursive(TreeNode* root, int& minDiff, int*& pPreVal) {
        if (!root) {
            return;
        }

        getMinimumDifference_Recursive(root->left, minDiff, pPreVal);

        if (pPreVal) {
            int diff = root->val - *pPreVal;
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        else {
            minDiff = numeric_limits<int>::max();
        }
        pPreVal = &(root->val);

        getMinimumDifference_Recursive(root->right, minDiff, pPreVal);
    }

    void getMinimumDifference_Iterative(TreeNode* root, int& minDiff, int*& pPreVal) {
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (pPreVal) {
                    int diff = node->val - *pPreVal;
                    if (diff < minDiff) {
                        minDiff = diff;
                    }
                }
                else {
                    minDiff = numeric_limits<int>::max();
                }
                pPreVal = &(node->val);
            }
            else {
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                stk.emplace(node, true);
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }
    }

    int getMinimumDifference(TreeNode* root) {
        int minDiff;
        int* pPreVal = nullptr;

        //getMinimumDifference_Recursive(root, minDiff, pPreVal);
        getMinimumDifference_Iterative(root, minDiff, pPreVal);

        return minDiff;
    }
};