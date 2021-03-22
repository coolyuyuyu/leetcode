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
    vector<int> boundaryOfBinaryTree_Recursive(TreeNode* root) {
        vector<int> vals;
        vals.push_back(root->val);

        function<void(TreeNode*, vector<int>&)> lftBoundary = [&lftBoundary](TreeNode* root, vector<int>& vals) {
            if (!root || (!root->left && !root->right)) {
                return;
            }

            vals.push_back(root->val);
            if (root->left) {
                lftBoundary(root->left, vals);
            }
            else {
                lftBoundary(root->right, vals);
            }
        };
        lftBoundary(root->left, vals);

        function<void(TreeNode*, vector<int>&)> btmBoundary = [&btmBoundary](TreeNode* root, vector<int>& vals) {
            if (!root) {
                return;
            }

            if (!root->left && !root->right) {
                vals.push_back(root->val);
            }
            else {
                btmBoundary(root->left, vals);
                btmBoundary(root->right, vals);
            }
        };
        btmBoundary(root->left, vals);
        btmBoundary(root->right, vals);

        function<void(TreeNode*, vector<int>&)> rhtBoundary = [&rhtBoundary](TreeNode* root, vector<int>& vals) {
            if (!root || (!root->left && !root->right)) {
                return;
            }


            if (root->right) {
                rhtBoundary(root->right, vals);
            }
            else {
                rhtBoundary(root->left, vals);
            }
            vals.push_back(root->val);
        };
        rhtBoundary(root->right, vals);

        return vals;
    }

    vector<int> boundaryOfBinaryTree_Iterative(TreeNode* root) {
        vector<int> vals;
        vals.push_back(root->val);

        function<void(TreeNode*, vector<int>&)> lftBoundary = [](TreeNode* root, vector<int>& vals) {
            while (root && (root->left || root->right)) {
                vals.push_back(root->val);
                if (root->left) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
        };
        lftBoundary(root->left, vals);

        function<void(TreeNode*, vector<int>&)> btmBoundary = [](TreeNode* root, vector<int>& vals) {
            stack<TreeNode*> stk;
            if (root) {
                stk.push(root);
            }
            while (!stk.empty()) {
                root = stk.top();
                stk.pop();

                if (!root->left && !root->right) {
                    vals.push_back(root->val);
                }
                else {
                    if (root->right) {
                        stk.push(root->right);
                    }
                    if (root->left) {
                        stk.push(root->left);
                    }
                }
            }
        };
        btmBoundary(root->left, vals);
        btmBoundary(root->right, vals);

        function<void(TreeNode*, vector<int>&)> rhtBoundary = [&rhtBoundary](TreeNode* root, vector<int>& vals) {
            size_t size = vals.size();
            while (root && (root->left || root->right)) {
                vals.push_back(root->val);
                if (root->right) {
                    root = root->right;
                }
                else {
                    root = root->left;
                }
            }
            reverse(vals.begin() + size, vals.end());
        };
        rhtBoundary(root->right, vals);

        return vals;
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        //return boundaryOfBinaryTree_Recursive(root);
        return boundaryOfBinaryTree_Iterative(root);
    }
};