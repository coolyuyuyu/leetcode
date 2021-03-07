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
    void getLeaves_Recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        getLeaves_Recursive(root->left, vals);
        if (!root->left && !root->right) {
            vals.push_back(root->val);
        }
        getLeaves_Recursive(root->right, vals);
    }

    void getLeaves_Iterative(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (!node->left && !node->right) {
                vals.push_back(node->val);
            }
            else {
                if (node->right) {
                    stk.push(node->right);
                }
                if (node->left) {
                    stk.push(node->left);
                }
            }
        }
    }

    bool compareLeaves(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1, vals2;

        //getLeaves_Recursive(root1, vals1);
        //getLeaves_Recursive(root2, vals2);

        getLeaves_Iterative(root1, vals1);
        getLeaves_Iterative(root2, vals2);

        return (vals1 == vals2);
    }

    bool compareLeavesInTandem(TreeNode* root1, TreeNode* root2) {
        class LeafIterator {
        public:
            LeafIterator(TreeNode* root) {
                if (root) {
                    m_stk.push(root);
                }
            }

            bool hasNext() {
                while (!m_stk.empty()) {
                    TreeNode* node = m_stk.top();
                    if (!node->left && !node->right) {
                        return true;
                    }
                    m_stk.pop();

                    if (node->right) {
                        m_stk.push(node->right);
                    }
                    if (node->left) {
                        m_stk.push(node->left);
                    }
                }

                return false;
            }

            int next() {
                assert(!m_stk.empty());
                TreeNode* node = m_stk.top();
                assert(!node->left && !node->right);
                m_stk.pop();

                if (node->right) {
                    m_stk.push(node->right);
                }
                if (node->left) {
                    m_stk.push(node->left);
                }

                return node->val;
            }
        private:
            stack<TreeNode*> m_stk;
        };

        LeafIterator itr1(root1), itr2(root2);
        while (itr1.hasNext() && itr2.hasNext()) {
            if (itr1.next() != itr2.next()) {
                return false;
            }
        }

        return (!itr1.hasNext() && !itr2.hasNext());
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //return compareLeaves(root1, root2);

        return compareLeavesInTandem(root1, root2);
    }
};