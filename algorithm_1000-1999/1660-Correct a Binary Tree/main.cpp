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
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<TreeNode**> q({&root});
        while (!q.empty()) {
            unordered_set<TreeNode*> visited;
            for (int n = q.size(); 0 < n--;) {
                TreeNode** ppNode = q.front();
                q.pop();

                if ((*ppNode)->right) {
                    if (visited.find((*ppNode)->right) != visited.end()) {
                        *ppNode = nullptr;
                        return root;
                    }
                    q.push(&((*ppNode)->right));
                }
                if ((*ppNode)->left) {
                    q.push(&((*ppNode)->left));
                }
                visited.insert(*ppNode);
            }
        }

        return root;
    }
};
