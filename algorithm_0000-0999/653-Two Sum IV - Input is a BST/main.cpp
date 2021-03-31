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
    bool findTarget_Recursive(TreeNode* root, int k, unordered_set<int>& visited) {
        if (!root) {
            return false;
        }

        if (visited.find(k - root->val) != visited.end()) {
            return true;
        }
        visited.insert(root->val);

        return (findTarget_Recursive(root->left, k, visited) || findTarget_Recursive(root->right, k, visited));
    }

    bool findTarget_Iterative(TreeNode* root, int k) {
        unordered_set<int> visited;

        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            if (visited.find(k - root->val) != visited.end()) {
                return true;
            }
            visited.insert(root->val);

            if (root->right) {
                stk.push(root->right);
            }
            if (root->left) {
                stk.push(root->left);
            }
        }

        return false;
    }

    class BSTIterator {
    public:
        BSTIterator(TreeNode* root, bool reverse = false)
            : m_reverse(reverse) {
            for (; root; root = (m_reverse ? root->right : root->left)) {
                m_stk.emplace(root);
            }
        }

        bool hasNext() {
            return (!m_stk.empty());
        }

        TreeNode* next() {
            TreeNode* root = m_stk.top();
            m_stk.pop();

            for (TreeNode* node = (m_reverse ? root->left : root->right); node; node = (m_reverse ? node->right : node->left)) {
                m_stk.emplace(node);
            }

            return root;
        }

    private:
        bool m_reverse;
        stack<TreeNode*> m_stk;
    };

    bool findTarget_SearchFromBothEnd(TreeNode* root, int k) {
        BSTIterator itr1(root, false), itr2(root, true);
        TreeNode* node1 = (itr1.hasNext() ? itr1.next() : nullptr);
        TreeNode* node2 = (itr2.hasNext() ? itr2.next() : nullptr);
        while (node1 != node2) {
            int sum = node1->val + node2->val;
            if (sum < k) {
                node1 = itr1.next();
            }
            else if (sum == k) {
                return true;
            }
            else {
                node2 = itr2.next();
            }
        }

        return false;
    }


    bool findTarget(TreeNode* root, int k) {
        //unordered_set<int> visited;
        //return findTarget_Recursive(root, k, visited);

        //return findTarget_Iterative(root, k);

        return findTarget_SearchFromBothEnd(root, k);
    }
};
