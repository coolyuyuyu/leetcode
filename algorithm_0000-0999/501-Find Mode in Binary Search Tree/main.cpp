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
    vector<int> recursive(TreeNode* root) {
        int preVal = INT_MIN, maxCnt = 0, curCnt = 0;
        vector<int> ret;
        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return; }

            f(root->left);

            if (preVal != root->val) {
                curCnt = 1;
            }
            else {
                ++curCnt;
            }
            if (curCnt > maxCnt) {
                maxCnt = curCnt;
                ret = {root->val};
            }
            else if (curCnt == maxCnt) {
                ret.push_back(root->val);
            }
            preVal = root->val;

            f(root->right);
        };
        f(root);

        return ret;
    }

    vector<int> iterative(TreeNode* root) {
        int preVal = INT_MIN, maxCnt = 0, curCnt = 0;
        vector<int> ret;
        for (stack<TreeNode*> stk; root || !stk.empty();) {
            if (root) {
                while (root) {
                    stk.push(root);
                    root = root->left;
                }
            }
            else {
                root = stk.top();
                stk.pop();

                if (preVal != root->val) {
                    curCnt = 1;
                }
                else {
                    ++curCnt;
                }
                if (curCnt > maxCnt) {
                    maxCnt = curCnt;
                    ret = {root->val};
                }
                else if (curCnt == maxCnt) {
                    ret.push_back(root->val);
                }
                preVal = root->val;

                root = root->right;
            }
        }

        return ret;
    }

    vector<int> findMode(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
