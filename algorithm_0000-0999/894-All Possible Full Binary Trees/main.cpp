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
    Solution()
        : m_fbtGroups({{}, {new TreeNode(0)}}) {
    }

    vector<TreeNode*>& allPossibleFBT_Recursive(size_t n) {
        if (m_fbtGroups.size() <= n) {
            m_fbtGroups.resize(n + 1);
        }

        if (n % 2 == 0 || !m_fbtGroups[n].empty()) {
            return m_fbtGroups[n];
        }

        for (size_t i = 1; i < n; i += 2) {
            size_t j = n - i - 1;
            for (TreeNode* lft : allPossibleFBT_Recursive(i)) {
                for (TreeNode* rht : allPossibleFBT_Recursive(j)) {
                    m_fbtGroups[n].push_back(new TreeNode(0, lft, rht));
                }
            }
        }
        return m_fbtGroups[n];
    }

    vector<TreeNode*>& allPossibleFBT_Iterative(size_t n) {
        for (size_t i = m_fbtGroups.size(); i <= n; ++i) {
            m_fbtGroups.push_back(vector<TreeNode*>(0));
            if (i % 2 == 0) {
                continue;
            }

            for (size_t lftIndex = 1; lftIndex < i; lftIndex += 2) {
                size_t rhtIndex = i - lftIndex - 1;
                for (TreeNode* lft : allPossibleFBT_Recursive(lftIndex)) {
                    for (TreeNode* rht : allPossibleFBT_Recursive(rhtIndex)) {
                        m_fbtGroups[i].push_back(new TreeNode(0, lft, rht));
                    }
                }
            }
        }

        return m_fbtGroups[n];
    }

    vector<TreeNode*>& allPossibleFBT(size_t n) {
        //return allPossibleFBT_Recursive(n);
        return allPossibleFBT_Iterative(n);
    }

private:
    vector<vector<TreeNode*>> m_fbtGroups;
};