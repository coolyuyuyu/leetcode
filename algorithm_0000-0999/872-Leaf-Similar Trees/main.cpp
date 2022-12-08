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
    void collectLeaf_recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        collectLeaf_recursive(root->left, vals);
        if (!root->left && !root->right) {
            vals.push_back(root->val);
        }
        collectLeaf_recursive(root->right, vals);
    }

    bool compareAll_recursive(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1, vals2;
        collectLeaf_recursive(root1, vals1);
        collectLeaf_recursive(root2, vals2);
        return vals1 == vals2;
    }

    vector<int> collectLeaf_iterative(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        vector<int> vals;
        while (!stk.empty()) {
            root = stk.top();
            if (root->left == nullptr && root->right == nullptr) {
                vals.push_back(root->val);
            }
            stk.pop();

            if (root->right) {
                stk.push(root->right);
            }
            if (root->left) {
                stk.push(root->left);
            }
        }

        return vals;
    }

    bool compareAll_iterative(TreeNode* root1, TreeNode* root2) {
        return collectLeaf_iterative(root1) == collectLeaf_iterative(root2);
    }

    bool compare1by1(TreeNode* root1, TreeNode* root2) {
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
                    if (node->left == nullptr && node->right == nullptr) {
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
                assert(hasNext());
                bool b = hasNext();
                if (!b) {
                    assert(false);
                }

                TreeNode* node = m_stk.top();
                assert(node->left == nullptr && node->right == nullptr);

                m_stk.pop();

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

        return !(itr1.hasNext() || itr2.hasNext());
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //return compareAll_recursive(root1, root2);
        //return compareAll_iterative(root1, root2);
        return compare1by1(root1, root2);
    }
};
