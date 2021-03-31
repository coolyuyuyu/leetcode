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
    int sumEvenGrandparent_Recursive(TreeNode* root, TreeNode* parent = nullptr, TreeNode* grandParent = nullptr) {
        if (!root) {
            return 0;
        }

        int sum = sumEvenGrandparent_Recursive(root->left, root, parent) + sumEvenGrandparent_Recursive(root->right, root, parent);
        if (grandParent && grandParent->val % 2 == 0) {
            sum += root->val;
        }

        return sum;
    }

    int sumEvenGrandparent_Iterative(TreeNode* root) {
        int sum = 0;

        queue<tuple<TreeNode*, TreeNode*, TreeNode*>> q;
        if (root) {
            q.emplace(root, nullptr, nullptr);
        }
        while (!q.empty()) {
            TreeNode* node = get<0>(q.front());
            TreeNode* parent = get<1>(q.front());
            TreeNode* grandParent = get<2>(q.front());
            q.pop();

            if (grandParent && grandParent->val % 2 == 0) {
                sum += node->val;
            }

            if (node->left) {
                q.emplace(node->left, node, parent);
            }
            if (node->right) {
                q.emplace(node->right, node, parent);
            }
        }

        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return sumEvenGrandparent_Recursive(root);
        //return sumEvenGrandparent_Iterative(root);
    }
};