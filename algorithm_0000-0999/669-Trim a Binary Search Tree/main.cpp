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
    TreeNode* trimBST_Recursive(TreeNode* root, int low, int high) {
        if (!root) {
            return nullptr;
        }
        if (root->val < low) {
            return trimBST_Recursive(root->right, low, high);
        }
        if (high < root->val) {
            return trimBST_Recursive(root->left, low, high);
        }

        root->left = trimBST_Recursive(root->left, low, root->val);
        root->right = trimBST_Recursive(root->right, root->val, high);
        return root;
    }

    TreeNode* trimBST_Iterative(TreeNode* root, int low, int high) {
        queue<tuple<TreeNode**, int, int>> q; // <root, low, high>;
        if (root) {
            q.emplace(&root, low, high);
        }
        while (!q.empty()) {
            TreeNode** ppNode = get<0>(q.front());
            int low = get<1>(q.front());
            int high = get<2>(q.front());
            q.pop();

            if ((*ppNode)->val < low) {
                cout << (*ppNode)->val << endl;
                *ppNode = (*ppNode)->right;
                if (*ppNode) {
                    q.emplace(ppNode, low, high);
                }
            }
            else if (high < (*ppNode)->val) {
                *ppNode = (*ppNode)->left;
                if (*ppNode) {
                    q.emplace(ppNode, low, high);
                }
            }
            else {
                if ((*ppNode)->left) {
                    q.emplace(&((*ppNode)->left), low, (*ppNode)->val);
                }
                if ((*ppNode)->right) {
                    q.emplace(&((*ppNode)->right), (*ppNode)->val, high);
                }
            }
        }

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //return trimBST_Recursive(root, low, high) ;
        return trimBST_Iterative(root, low, high) ;
    }
};