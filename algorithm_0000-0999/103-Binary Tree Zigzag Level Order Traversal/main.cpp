/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        bool reverseNums = false;

        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            ret.push_back(vector<int>());
            vector<int>& nums = ret.back();
            for (size_t n = nodes.size(); n > 0; --n) {
                TreeNode* node = nodes.front();
                nodes.pop();

                nums.push_back(node->val);

                TreeNode* lft = node->left;
                if (lft) {
                    nodes.push(lft);
                }
                TreeNode* rht = node->right;
                if (rht) {
                    nodes.push(rht);
                }
            }

            if (reverseNums) {
                reverse(nums.begin(), nums.end());
            }

            reverseNums = !reverseNums;
        }

        return ret;
    }
};