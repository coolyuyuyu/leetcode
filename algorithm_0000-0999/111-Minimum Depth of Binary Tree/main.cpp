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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        int depth = 1;
        while (!nodes.empty()) {
            size_t count = nodes.size();
            for (size_t i = 0; i < count; ++i) {
                TreeNode* pNode = nodes.front();
                nodes.pop();
                if (pNode->left) {
                    nodes.push(pNode->left);
                    if (pNode->right) {
                        nodes.push(pNode->right);
                    }
                    else {
                    
                    }
                }
                else {
                    if (pNode->right) {
                        nodes.push(pNode->right);
                    }
                    else {
                        return depth;
                    }
                }
            }
            ++depth;
        }
    }
};