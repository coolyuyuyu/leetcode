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
    TreeNode* delNodes_Recursive(TreeNode* root, set<int>& targets, vector<TreeNode*>& result, bool isRoot = true) {
        if (!root) {
            return nullptr;
        }

        bool deleted = (targets.find(root->val) != targets.end());
        if (isRoot && !deleted) {
            result.push_back(root);
        }

        root->left = delNodes_Recursive(root->left, targets, result, deleted);
        root->right = delNodes_Recursive(root->right, targets, result, deleted);

        return (deleted ? nullptr : root);
    }

    vector<TreeNode*> delNodes_Iterative(TreeNode* root, set<int>& targets) {
        vector<TreeNode*> ans;

        queue<TreeNode*> trees;
        if (root) {
            trees.push(root);
        }
        while (!trees.empty()) {
            TreeNode* root = trees.front();
            trees.pop();

            if (targets.find(root->val) == targets.end()) {
                ans.push_back(root);
            }

            queue<TreeNode**> nodes({&root});
            while (!nodes.empty()) {
                TreeNode** ppNode = nodes.front();
                nodes.pop();

                if (targets.find((*ppNode)->val) != targets.end()) {
                    if ((*ppNode)->left) {
                        trees.push((*ppNode)->left);
                    }
                    if ((*ppNode)->right) {
                        trees.push((*ppNode)->right);
                    }
                    *ppNode = nullptr;
                }
                else {
                    if ((*ppNode)->left) {
                        nodes.push(&((*ppNode)->left));
                    }
                    if ((*ppNode)->right) {
                        nodes.push(&((*ppNode)->right));
                    }
                }
            }

        }

        return ans;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> targets(to_delete.begin(), to_delete.end());

        //vector<TreeNode*> result;
        //delNodes_Recursive(root, targets, result);
        //return result;

        return delNodes_Iterative(root, targets);
    }
};