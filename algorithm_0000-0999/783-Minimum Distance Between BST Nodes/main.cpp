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
    int minDiffInBST_Recursive(TreeNode* root, int*& pMinVal, int*& pMaxVal) {
        if (!root) {
            pMinVal = pMaxVal = nullptr;
            return numeric_limits<int>::max();
        }

        int *pLftMinVal, *pLftMaxVal;
        int minDiffLft = minDiffInBST_Recursive(root->left, pLftMinVal, pLftMaxVal);
        pMinVal = pLftMinVal ? pLftMinVal : &(root->val);

        int *pRhtMinVal, *pRhtMaxVal;
        int minDiffRht = minDiffInBST_Recursive(root->right, pRhtMinVal, pRhtMaxVal);
        pMaxVal = pRhtMaxVal ? pRhtMaxVal : &(root->val);

        int minDiff = min(minDiffLft, minDiffRht);
        if (pLftMaxVal) {
            minDiff = min(minDiff, root->val - *pLftMaxVal);
        }
        if (pRhtMaxVal) {
            minDiff = min(minDiff, *pRhtMinVal - root->val);
        }

        return minDiff;
    }

    int minDiffInBST_Iterative(TreeNode* root) {
        int preVal = numeric_limits<int>::min();
        int minDiff = numeric_limits<int>::max();

        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();

                int diff = (preVal == numeric_limits<int>::min() ? numeric_limits<int>::max() : (root->val - preVal));
                if (diff < minDiff) {
                    minDiff = diff;
                }
                preVal = root->val;

                root = root->right;
            }
        }

        return minDiff;
    }

    int minDiffInBST(TreeNode* root) {
        //int *pMinVal, *pMaxVal;
        //return minDiffInBST_Recursive(root, pMinVal, pMaxVal);

        return minDiffInBST_Iterative(root);
    }
};