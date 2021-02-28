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
    int largestBSTSubtree(TreeNode* root) {
        int nodeCnt;
        int minVal, maxVal;
        int maxNodeCount = 0;
        largestBSTSubtreeHelper(root, nodeCnt, minVal, maxVal, maxNodeCount);
        return maxNodeCount;
    }

    bool largestBSTSubtreeHelper(TreeNode* root, int& nodeCnt, int& minVal, int& maxVal, int& maxNodeCount) {
        if (root) {
            int lftNodeCnt;
            int lftMinVal, lftMaxVal;
            bool lftBST = largestBSTSubtreeHelper(root->left, lftNodeCnt, lftMinVal, lftMaxVal, maxNodeCount);

            int rhtNodeCnt;
            int rhtMinVal, rhtMaxVal;
            bool rhtBST = largestBSTSubtreeHelper(root->right, rhtNodeCnt, rhtMinVal, rhtMaxVal, maxNodeCount);

            if (lftBST && rhtBST) {
                if ((lftNodeCnt == 0 || lftMaxVal < root->val) && (rhtNodeCnt == 0 || root->val < rhtMinVal)) {
                    nodeCnt = lftNodeCnt + 1 + rhtNodeCnt;
                    minVal = (lftNodeCnt == 0 ? root->val : lftMinVal);
                    maxVal = (rhtNodeCnt == 0 ? root->val : rhtMaxVal);
                    maxNodeCount = max(maxNodeCount, nodeCnt);
                    return true;
                }
            }

            return false;
        }
        else {
            nodeCnt = 0;
            return true;
        }
    }
};