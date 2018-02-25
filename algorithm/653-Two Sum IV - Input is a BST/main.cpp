/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator{
public:
    BSTIterator(TreeNode* root, bool forward)
        : m_forward(forward) {
        while (root) {
            m_stk.push(root);
            root = m_forward ? root->left : root->right;
        }
    }

    bool hasNext() {
        return !m_stk.empty();
    }

    TreeNode* next() {
        TreeNode* node = m_stk.top();
        m_stk.pop();

        TreeNode* root = m_forward ? node->right : node->left;
        while (root) {
            m_stk.push(root);
            root = m_forward ? root->left : root->right;
        }

        return node;
    }

private:
    stack<TreeNode*> m_stk;
    bool m_forward;
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        /*
        unordered_set<int> candidates;
        return findTargetHelper(root, k, candidates);
        */

        BSTIterator forward(root, true);
        BSTIterator backward(root, false);
        TreeNode* nodeA = forward.hasNext() ? forward.next() : NULL;
        TreeNode* nodeB = backward.hasNext() ? backward.next() : NULL;
        while (nodeA != nodeB) {
            int sum = nodeA->val + nodeB->val;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                nodeA = forward.next();
            }
            else {
                nodeB = backward.next();
            }
        }

        return false;
    }

    bool findTargetHelper(TreeNode* root, int k, unordered_set<int>& candidates) {
        if (root) {
            pair<unordered_set<int>::iterator, bool> p = candidates.insert(root->val);
            if (p.second == false) {
                return true;
            }
            else {
                candidates.insert(k - root->val);
                return findTargetHelper(root->left, k, candidates) || findTargetHelper(root->right, k, candidates);
            }
        }
        else {
            return false;
        }
    }
};