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
    bool recursive(TreeNode* p, TreeNode* q) {
        if (p == q) {
            return true;
        }
        else {
            return
                p && q && p->val == q->val &&
                recursive(p->left, q->left) &&
                recursive(p->right, q->right);
        }
    }

    bool iterative(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> nodeQ;

        nodeQ.emplace(p, q);
        while (!nodeQ.empty()) {
            p = nodeQ.front().first;
            q = nodeQ.front().second;
            nodeQ.pop();

            if (!p && !q) {
                continue;
            }
            if ((p && !q) || (!p && q) || (p->val != q->val)) {
                return false;
            }
            nodeQ.emplace(p->left, q->left);
            nodeQ.emplace(p->right, q->right);
        }

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        //return recursive(p, q);
        return iterative(p, q);
    }
};
