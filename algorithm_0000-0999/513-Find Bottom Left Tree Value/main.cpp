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
    void findBottomLeftValue_Recursive(TreeNode* root, int depth, int& outDepth, int& outVal) {
        if (!root) {
            return;
        }

        if (outDepth < depth) {
            outDepth = depth;
            outVal = root->val;
        }

        findBottomLeftValue_Recursive(root->left, depth + 1, outDepth, outVal);
        findBottomLeftValue_Recursive(root->right, depth + 1, outDepth, outVal);
    }

    int findBottomLeftValue_Iterative(TreeNode* root) {
        // reverse level-order traversal
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            root = q.front();
            q.pop();

            if (root->right) {
                q.push(root->right);
            }
            if (root->left) {
                q.push(root->left);
            }
        }

        return root->val;
    }

    int findBottomLeftValue(TreeNode* root) {
        //int outDepth = -1;
        //int outVal;
        //findBottomLeftValue_Recursive(root, 0, outDepth, outVal);
        //return outVal;

        return findBottomLeftValue_Iterative(root);
    }
};