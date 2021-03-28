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
    int distributeCoins_Recursive(TreeNode* root, int& numOfMoves) {
        if (!root) {
            return 0;
        }

        int lftRemainingCoins = distributeCoins_Recursive(root->left, numOfMoves);
        int rhtRemainingCoins = distributeCoins_Recursive(root->right, numOfMoves);

        numOfMoves += (abs(lftRemainingCoins) + abs(rhtRemainingCoins));

        return (root->val + lftRemainingCoins + rhtRemainingCoins - 1);
    }

    void distributeCoins_Iterative(TreeNode* root, int& numOfMoves) {
        map<TreeNode*, int> m; // <node, remainingCoins>

        stack<pair<TreeNode*, bool>> stk; // <node, visited>;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                int lftRemainingCoins = (node->left ? m[node->left] : 0);
                int rhtRemainingCoins = (node->right ? m[node->right] : 0);

                numOfMoves += (abs(lftRemainingCoins) + abs(rhtRemainingCoins));

                m[node] = node->val + lftRemainingCoins + rhtRemainingCoins - 1;
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
    }

    int distributeCoins(TreeNode* root) {
        int numOfMoves = 0;

        //distributeCoins_Recursive(root, numOfMoves);
        distributeCoins_Iterative(root, numOfMoves);

        return numOfMoves;
    }
};