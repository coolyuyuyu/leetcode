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
    vector<TreeNode*> splitBST_Recursive(TreeNode* root, int V) {
        if (!root) {
            return {nullptr, nullptr};
        }

        vector<TreeNode*> ans;
        if (root->val <= V){
            ans = splitBST_Recursive(root->right, V);
            root->right = ans[0];
            ans[0] = root;
        }
        else {
            ans = splitBST_Recursive(root->left, V);
            root->left = ans[1];
            ans[1] = root;
        }

        return ans;
    }

    vector<TreeNode*> splitBST_Iterative(TreeNode* root, int V) {
        TreeNode* pLftRoot = nullptr;
        TreeNode* pRhtRoot = nullptr;
        TreeNode** ppLftNode = &pLftRoot;
        TreeNode** ppRhtNode = &pRhtRoot;
        while (root) {
            if (root->val <= V) {
                *ppLftNode = root;
                root = root->right;
                ppLftNode = &((*ppLftNode)->right);\

                *ppLftNode = nullptr;
                *ppRhtNode = root;
            }
            else {
                *ppRhtNode = root;
                root = root->left;
                ppRhtNode = &((*ppRhtNode)->left);

                *ppRhtNode = nullptr;
                *ppLftNode = root;
            }
        }

        return {pLftRoot,  pRhtRoot};
    }

    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        //return splitBST_Recursive(root, V);
        return splitBST_Iterative(root, V);
    }
};