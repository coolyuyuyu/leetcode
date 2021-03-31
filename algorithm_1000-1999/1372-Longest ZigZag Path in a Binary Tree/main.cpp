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
    int longestZigZag_Recursive(TreeNode* root, pair<int, int>& lenPair) {
        if (!root) {
            lenPair = {0, 0};
            return 0;
        }

        pair<int, int> lftLenPair, rhtLenPair;
        int lftMax = longestZigZag_Recursive(root->left, lftLenPair);
        int rhtMax = longestZigZag_Recursive(root->right, rhtLenPair);

        lenPair = {lftLenPair.second + 1, rhtLenPair.first + 1};

        return max(max(lftMax, rhtMax), max(lenPair.first, lenPair.second));
    }

    int longestZigZag_Iterative(TreeNode* root) {
        int maxLen = 0;

        unordered_map<TreeNode*, pair<int, int>> m; // <node, len pair>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                pair<int, int> lftLenPair = (node->left ? m[node->left] : make_pair(0, 0));
                pair<int, int> rhtLenPair = (node->right ? m[node->right] : make_pair(0, 0));
                pair<int, int> lenPair = {lftLenPair.second + 1, rhtLenPair.first + 1};

                maxLen = max(maxLen, max(lenPair.first, lenPair.second));

                m[node] = lenPair;
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

        return maxLen;
    }

    int longestZigZag(TreeNode* root) {
        //pair<int, int> lenPair;
        //return longestZigZag_Recursive(root, lenPair) - 1;

        return longestZigZag_Iterative(root) - 1;
    }
};