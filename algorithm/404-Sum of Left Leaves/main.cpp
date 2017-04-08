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
    int sumOfLeftLeaves(TreeNode* root) {
        struct State {
            State(TreeNode* n, bool b)
                : node(n)
                , leftChild(b)
            {}
            TreeNode* node;
            bool leftChild;
        };

        unordered_set<int> results;
        stack<State> stk;
        if (root) {
            stk.push(State(root, false));
        }

        int sum = 0;
        while (!stk.empty()) {
            State state = stk.top();
            stk.pop();

            if (state.node->left) {
                stk.push(State(state.node->left, true));
                if (state.node->right) {
                    stk.push(State(state.node->right, false));
                }
            }
            else {
                if (state.node->right) {
                    stk.push(State(state.node->right, false));
                }
                else {
                    if (state.leftChild) {
                        sum += state.node->val;
                    }
                }

            }
        }

        return sum;
    }
};