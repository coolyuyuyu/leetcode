/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ints;

        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            ints.push_back(nodes.back()->val);

            for (size_t n = nodes.size(); n > 0; --n) {
                TreeNode* pNode = nodes.front();
                nodes.pop();

                if (pNode->left) {
                    nodes.push(pNode->left);
                }
                if (pNode->right) {
                    nodes.push(pNode->right);
                }
            }
        }

        return ints;
    }
};