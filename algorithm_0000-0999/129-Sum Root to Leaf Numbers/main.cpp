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
    int sumNumbers(TreeNode* root) {
        return sumNumbersDFS(root);
    }

    int sumNumbersBFS(TreeNode* root) {
        int sumNums = 0;

        int num = 0;
        TreeNode* cur = root;

        queue<pair<TreeNode*, int>> pairs;
        if (root) {
            pairs.push(pair<TreeNode*, int>(root, 0));
        }

        while (!pairs.empty()) {
            for (size_t n = pairs.size(); n > 0; --n) {
                pair<TreeNode*, int> p = pairs.front();
                pairs.pop();

                TreeNode* node = p.first;
                int num = p.second * 10 + node->val;
                if (node->left) {
                    pairs.push(pair<TreeNode*, int>(node->left, num));
                    if (node->right) {
                        pairs.push(pair<TreeNode*, int>(node->right, num));
                    }
                    else {
                    }
                }
                else {
                    if (node->right) {
                        pairs.push(pair<TreeNode*, int>(node->right, num));
                    }
                    else {
                        sumNums += num;
                    }
                }
            }
        }

        return sumNums;
    }

    int sumNumbersDFS(TreeNode* root) {
        int sumNums = 0;

        int num = 0;
        TreeNode* cur = root;

        stack<pair<TreeNode*, int>> pairs;
        while (cur || !pairs.empty()) {
            if (cur) {
                pairs.push(pair<TreeNode*, int>(cur, num));

                num = num * 10 + cur->val;
                cur = cur->left;
            }
            else {
                pair<TreeNode*, int> p = pairs.top();
                pairs.pop();



                cur = p.first;
                num = p.second;

                num = num * 10 + cur->val;
                if (cur->left == NULL && cur->right == NULL) {
                    sumNums += num;
                }
                cur = cur->right;
            }

        }

        return sumNums;
    }
};