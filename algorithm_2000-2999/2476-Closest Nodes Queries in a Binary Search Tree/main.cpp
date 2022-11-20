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
    // Time: O(logn * q), Space: O(1), TLE (worst case for skewed tree)
    vector<vector<int>> searchTree(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        for (int query : queries) {
            vector<int> range = {-1, -1};
            for (const TreeNode* node = root; node;) {
                if (node->val == query) {
                    range = {node->val, node->val};
                    break;
                }
                else if (node->val < query) {
                    range[0] = node->val;
                    node = node->right;
                }
                else {
                    range[1] = node->val;
                    node = node->left;
                }
            }
            ans.push_back(range);
        }

        return ans;
    }

    // Time: O(logn * q), Space: O(n)
    vector<vector<int>> searchSortedSequence(TreeNode* root, vector<int>& queries) {
        vector<int> nums; {
            stack<TreeNode*> stk;
            for (TreeNode* node = root; node || !stk.empty();) {
                if (node) {
                    stk.push(node);
                    node = node->left;
                }
                else {
                    node = stk.top();
                    stk.pop();

                    nums.push_back(node->val);

                    node = node->right;
                }
            }
        }

        vector<vector<int>> ans;
        for (int query : queries) {
            vector<int> range = {-1, -1};
            auto itr = std::lower_bound(nums.begin(), nums.end(), query);
            if (itr == nums.end()) {
                range[0] = *(itr - 1) ;
            }
            else {
                range[1] = *itr;
                if (*itr == query) {
                    range[0] = *itr;
                }
                else {
                    if (itr != nums.begin()) {
                        range[0] = *(itr - 1) ;
                    }
                }
            }
            ans.push_back(range);
        }

        return ans;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        //return searchTree(root, queries);
        return searchSortedSequence(root, queries);
    }
};
