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
    void findMode_Recursive(TreeNode* root, vector<int>& mode, int& count, int& maxCount, int*& pPreVal) {
        if (!root) {
            return;
        }

        findMode_Recursive(root->left, mode, count, maxCount, pPreVal);

        if (pPreVal) {
            if (*pPreVal == root->val) {
                ++count;
            }
            else {
                pPreVal = &(root->val);
                count = 1;
            }

            if (maxCount < count) {
                maxCount = count;
                mode.clear();
                mode.push_back(root->val);
            }
            else if (maxCount == count) {
                mode.push_back(root->val);
            }
        }
        else {
            pPreVal = &(root->val);
            count = maxCount = 1;
            mode.push_back(root->val);
        }

        findMode_Recursive(root->right, mode, count, maxCount, pPreVal);
    }

    void findMode_Iterative(TreeNode* root, vector<int>& mode, int& count, int& maxCount, int*& pPreVal) {
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
                    if (*pPreVal == node->val) {
                        ++count;
                    }
                    else {
                        pPreVal = &(node->val);
                        count = 1;
                    }

                    if (maxCount < count) {
                        maxCount = count;
                        mode.clear();
                        mode.push_back(node->val);
                    }
                    else if (maxCount == count) {
                        mode.push_back(node->val);
                    }
                }
                else {
                    pPreVal = &(node->val);
                    count = maxCount = 1;
                    mode.push_back(node->val);
                }
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

    vector<int> findMode(TreeNode* root) {
        vector<int> mode;
        int count = 0, maxCount = 0;
        int* pPreVal = nullptr;

        //findMode_Recursive(root, mode, count, maxCount, pPreVal);
        findMode_Iterative(root, mode, count, maxCount, pPreVal);

        return mode;
    }
};