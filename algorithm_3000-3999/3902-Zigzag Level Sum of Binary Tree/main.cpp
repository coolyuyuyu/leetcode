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
    vector<long long> zigzagLevelSum(TreeNode* root) {
        vector<long long> ret;

        list<TreeNode*> l({root});
        for (bool odd = true; !l.empty(); odd = !odd) {
            bool stop = false;
            long long val = 0;
            for (int i = l.size(); 0 < i--;) {
                auto node = l.front();
                l.pop_front();

                TreeNode *lft = node->left, *rht = node->right;
                if (!odd) { std::swap(lft, rht); }

                if (lft) {
                    l.push_back(lft);
                }
                else {
                    stop = true;
                }
                if (!stop) {
                    val += node->val;
                }
                if (rht) {
                    l.push_back(rht);
                }
            }
            std::reverse(l.begin(), l.end());
            ret.push_back(val);
        }
        return ret;
    }
};
