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
    // straightforward for binary tree
    // Time: O(N)
    int countNodes_recursive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + countNodes_recursive(root->left) + countNodes_recursive(root->right);
    }

    // straightforward for binary tree
    // Time: O(N)
    int countNodes_iterative(TreeNode* root) {
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        int cnt = 0;
        while (!nodes.empty()) {
            ++cnt;

            TreeNode* node = nodes.front();
            nodes.pop();

            if (node->left) {
                nodes.push(node->left);
            }
            if (node->right) {
                nodes.push(node->right);
            }
        }

        return cnt;
    }

    int completeHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            ++h;
            root = root->left;
        }

        return h;
    }

    // take advantage of property of complete binary tree
    // Time: O((logN)^2)
    int countCompleteTreeNodes_recursive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lftH = completeHeight(root->left);
        int rhtH = completeHeight(root->left);
        if (lftH == rhtH) {
            return 1 + (1 << lftH) - 1 + countCompleteTreeNodes_recursive(root->right);
        }
        else {
            return 1 + countCompleteTreeNodes_recursive(root->left) + (1 << rhtH) - 1;
        }
    }

    // take advantage of property of complete binary tree
    // less number of completeHeight, compared to countCompleteTreeNodes_recursive
    // Time: O((logN)^2)
    int countCompleteTreeNodes_recursive2(TreeNode* root, int h) {
        if (!root) {
            return 0;
        }

        if ((completeHeight(root->right) + 1) == h) {
            return (1 << (h - 1)) + countCompleteTreeNodes_recursive2(root->right, h - 1);
        }
        else {
            return (1 << (h - 2)) + countCompleteTreeNodes_recursive2(root->left, h - 1);
        }
    }

    // take advantage of property of complete binary tree
    // Time: O((logN)^2)
    int countCompleteTreeNodes_iterative(TreeNode* root) {
        int cnt = 0;
        for (int h = completeHeight(root); root; h--) {
            if ((completeHeight(root->right) + 1) == h) {
                root = root->right;
                cnt += 1 << (h - 1);
            }
            else {
                root = root->left;
                cnt += 1 << (h - 2);
            }
        }

        return cnt;
    }

    int countNodes(TreeNode* root) {
        //return countNodes_recursive(root);
        //return countNodes_iterative(root);

        //return countCompleteTreeNodes_recursive(root);
        //return countCompleteTreeNodes_recursive2(root, completeHeight(root));
        return countCompleteTreeNodes_iterative(root);
    }
};
