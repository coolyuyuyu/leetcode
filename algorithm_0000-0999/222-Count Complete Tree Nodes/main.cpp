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
    int lftHeight(TreeNode* root) {
        return root ? (1 + lftHeight(root->left)) : 0;
    }

    // Time: O((logN)^2)
    int countNodes_Recursive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lftH = lftHeight(root->left);
        int rhtH = lftHeight(root->right);
        assert(lftH == rhtH || lftH == (rhtH + 1));
        if (lftH == rhtH) {
            return 1 + (1 << lftH) - 1 + countNodes_Recursive(root->right);
        }
        else {
            return 1 +  (1 << rhtH) - 1 + countNodes_Recursive(root->left);
        }
    }

    // Time: O((logN)^2)
    int countNodes_Itertive(TreeNode* root) {
        int numNodes = 0;

        for (int h = lftHeight(root); root; --h) {
            if ((lftHeight(root->right) + 1) == h) {
                numNodes += (1 << (h - 1));
                root = root->right;
            }
            else {
                numNodes += (1 << (h - 2));
                root = root->left;
            }
        }

        return numNodes;
    }

    int countNodes(TreeNode* root) {
        //return countNodes_Recursive(root);
        return countNodes_Itertive(root);
    }
};