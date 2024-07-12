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
    vector<TreeNode*> recursive(TreeNode* root, int target) {
        std::function<pair<TreeNode*, TreeNode*>(TreeNode*)> f = [&](TreeNode* root) -> pair<TreeNode*, TreeNode*> {
            if (!root) { return {nullptr, nullptr}; }

            if (root->val <= target) {
                auto [childRoot1, childRoot2] = f(root->right);
                root->right = childRoot1;
                return {root, childRoot2};
            }
            else {
                auto [childRoot1, childRoot2] = f(root->left);
                root->left = childRoot2;
                return {childRoot1, root};
            }
        };

        auto [ret1, ret2] = f(root);
        return {ret1, ret2};
    }

    vector<TreeNode*> iterative(TreeNode* root, int target) {
        TreeNode *pRoot1 = nullptr, *pRoot2 = nullptr;
        for (TreeNode **ppNode1 = &pRoot1, **ppNode2 = &pRoot2; root;) {
            if (root->val <= target) {
                *ppNode1 = root;
                *ppNode2 = root->right;
                ppNode1 = &((*ppNode1)->right);
                root = root->right;
                *ppNode1 = nullptr;
            }
            else {
                *ppNode2 = root;
                *ppNode1 = root->left;
                ppNode2 = &((*ppNode2)->left);
                root = root->left;
                *ppNode2 = nullptr;
            }
        }

        return {pRoot1, pRoot2};
    }

    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        //return recursive(root, target);
        return iterative(root, target);
    }
};
