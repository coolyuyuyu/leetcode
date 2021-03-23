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
    void addOneRow_Recursive(TreeNode* root, int val, int depth) {
        if (!root) {
            return;
        }

        if (--depth == 0) {
            //cout << "root->val:" << root->val << endl;
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);

        }
        else {
            addOneRow_Recursive(root->left, val, depth);
            addOneRow_Recursive(root->right, val, depth);
        }
    }

    void addOneRow_Iterative(TreeNode* root, int val, int depth) {
        if (!root) {
            return;
        }

        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (0 <--depth && !q.empty()) {
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
    }

    TreeNode* addOneRow_Helper(TreeNode* root, int val, int depth) {
        assert(1 <= depth);
        if (depth == 1) {
            root = new TreeNode(val, root, nullptr);
        }
        else {
            //addOneRow_Recursive(root, val, --depth);
            addOneRow_Iterative(root, val, --depth);
        }

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return addOneRow_Helper(root, val, depth);
    }
};