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
    class BSTIterator {
    public:
        BSTIterator(TreeNode* root) {
            for (; root; root = root->left) {
                m_stk.push(root);
            }
        }

        TreeNode* next() {
            if (m_stk.empty()) {
                return nullptr;
            }

            TreeNode* node = m_stk.top();
            m_stk.pop();

            for (TreeNode* root = node->right; root; root = root->left) {
                m_stk.push(root);
            }

            return node;
        }
    private:
        stack<TreeNode*> m_stk;
    };

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;

        BSTIterator itr1(root1), itr2(root2);
        TreeNode* node1 = itr1.next();
        TreeNode* node2 = itr2.next();
        while (node1 && node2) {
            if (node1->val < node2->val) {
                ret.push_back(node1->val);
                node1 = itr1.next();
            }
            else if (node1->val == node2->val) {
                ret.push_back(node1->val);
                ret.push_back(node2->val);
                node1 = itr1.next();
                node2 = itr2.next();
            }
            else {
                ret.push_back(node2->val);
                node2 = itr2.next();
            }
        }

        BSTIterator& itr = node1 ? itr1 : itr2;
        for (TreeNode* node = (node1 ? node1 : node2); node; node = itr.next()) {
            ret.push_back(node->val);
        }

        return ret;
    }
};