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
    bool largestBSTSubtree_Recursive(TreeNode* root, int& numNodes, int& maxNumNodes, int* pMinVal = nullptr, int* pMaxVal = nullptr) {
        if (!root) {
            numNodes = 0;
            return true;
        }

        int lftMinVal, lftMaxVal, lftNumNodes;
        bool lftBST = largestBSTSubtree_Recursive(root->left, lftNumNodes, maxNumNodes, &lftMinVal, &lftMaxVal);
        int rhtMinVal, rhtMaxVal, rhtNumNodes;
        bool rhtBST = largestBSTSubtree_Recursive(root->right, rhtNumNodes, maxNumNodes, &rhtMinVal, &rhtMaxVal);
        if (lftBST && rhtBST && (lftNumNodes == 0 || lftMaxVal < root->val) && (rhtNumNodes == 0 || root->val < rhtMinVal)) {
            numNodes = lftNumNodes + 1 + rhtNumNodes;
            if (maxNumNodes < numNodes) {
                maxNumNodes = numNodes;
            }

            if (pMinVal) {
                *pMinVal = (lftNumNodes == 0 ? root->val : lftMinVal);
            }
            if (pMaxVal) {
                *pMaxVal = (rhtNumNodes == 0 ? root->val : rhtMaxVal);
            }

            return true;
        }
        else {
            return false;
        }
    }

    int largestBSTSubtree_Iterative(TreeNode* root) {
        int maxNumNodes = 0;

        map<TreeNode*, tuple<int, int, int>> m; // <node, <numNodes, minVal, maxVal>>
        // postorder traversal
        stack<pair<TreeNode*, bool>> stk; // <node, visited>
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                bool lftBST = (node->left ? m.find(node->left) != m.end() : true);
                bool rhtBST = (node->right ? m.find(node->right) != m.end() : true);
                if (lftBST && rhtBST) {
                    int lftNumNodes = (node->left ? get<0>(m[node->left]) : 0);
                    int rhtNumNodes = (node->right ? get<0>(m[node->right]) : 0);
                    if ((lftNumNodes == 0 || get<2>(m[node->left]) < node->val) && (rhtNumNodes == 0 || node->val < get<1>(m[node->right]))) {
                        int numNodes = lftNumNodes + 1 + rhtNumNodes;
                        if (maxNumNodes < numNodes) {
                            maxNumNodes = numNodes;
                        }

                        int minVal = (lftNumNodes == 0 ? node->val : get<1>(m[node->left]));
                        int maxVal = (rhtNumNodes == 0 ? node->val : get<2>(m[node->right]));
                        m.emplace(node, make_tuple(numNodes, minVal, maxVal));
                    }
                }

            }
            else {
                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return maxNumNodes;

    }

    int largestBSTSubtree(TreeNode* root) {
        //int numNodes, maxNumNodes = 0;
        //largestBSTSubtree_Recursive(root, numNodes, maxNumNodes);
        //return maxNumNodes;

        return largestBSTSubtree_Iterative(root);
    }
};