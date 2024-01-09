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
class LeafIterator {
public:
    LeafIterator(TreeNode* root) {
        if (root) {
            m_stk.push(root);
        }
    }

    TreeNode* next() {
        assert(hasNext());

        TreeNode* ret = m_stk.top();
        m_stk.pop();

        return ret;
    }

    bool hasNext() const {
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

private:
    mutable stack<TreeNode*> m_stk;
};

class Solution {
public:
    bool compareAll_recursive(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        std::function<void(TreeNode*, vector<int>&)> f = [&](TreeNode* root, vector<int>& nums) {
            if (!root) { return; }

            f(root->left, nums);
            if (root->left == nullptr && root->right == nullptr) {
                nums.push_back(root->val);
            }
            f(root->right, nums);
        };
        f(root1, nums1);
        f(root2, nums2);

        return nums1 == nums2;
    }

    bool compareAll_iterative(TreeNode* root1, TreeNode* root2) {
        std::function<vector<int>(TreeNode*)> f = [&](TreeNode* root) {
            vector<int> nums;
            for (stack<TreeNode*> stk({root}); !stk.empty();) {
                auto root = stk.top();
                stk.pop();

                if (!root) { continue; }
                if (root->left == nullptr && root->right == nullptr) {
                    nums.push_back(root->val);
                }

                stk.push(root->right);
                stk.push(root->left);
            }

            return nums;
        };
        vector<int> nums1 = f(root1);
        vector<int> nums2 = f(root2);

        return nums1 == nums2;
    }

    bool compare1By1(TreeNode* root1, TreeNode* root2) {
        LeafIterator itr1(root1), itr2(root2);
        while (itr1.hasNext() && itr2.hasNext()) {
            int num1 = itr1.next()->val, num2 = itr2.next()->val;
            if (num1 != num2) {
                return false;
            }
        }
        if (itr1.hasNext() || itr2.hasNext()) {
            return false;
        }

        return true;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //return compareAll_recursive(root1, root2);
        //return compareAll_iterative(root1, root2);
        return compare1By1(root1, root2);
    }
};
