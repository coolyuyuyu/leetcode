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
    int longestUnivaluePath_Recursive(TreeNode* root, int& maxNumOfNodes) {
        if (!root) {
            return 0;
        }

        int lftNumOfNodesTopDown = longestUnivaluePath_Recursive(root->left, maxNumOfNodes);
        if (0 < lftNumOfNodesTopDown && root->left->val != root->val) {
            lftNumOfNodesTopDown = 0;
        }

        int rhtNumOfNodesTopDown = longestUnivaluePath_Recursive(root->right, maxNumOfNodes);
        if (0 < rhtNumOfNodesTopDown && root->right->val != root->val) {
            rhtNumOfNodesTopDown = 0;
        }

        int numOfNodes = lftNumOfNodesTopDown + 1 + rhtNumOfNodesTopDown;
        if (maxNumOfNodes < numOfNodes) {
            maxNumOfNodes = numOfNodes;
        }

        return (1 + max(lftNumOfNodesTopDown, rhtNumOfNodesTopDown));
    }

    void longestUnivaluePath_Iterative(TreeNode* root, int& maxNumOfNodes) {
        map<TreeNode*, int> m; // <node, maxNumOfNodesTopDown>

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
                int lftNumOfNodesTopDown = (node->left ? m[node->left] : 0);
                if (0 < lftNumOfNodesTopDown && node->left->val != node->val) {
                    lftNumOfNodesTopDown = 0;
                }
                int rhtNumOfNodesTopDown = (node->right ? m[node->right] : 0);
                if (0 < rhtNumOfNodesTopDown && node->right->val != node->val) {
                    rhtNumOfNodesTopDown = 0;
                }

                int numOfNodes = lftNumOfNodesTopDown + 1 + rhtNumOfNodesTopDown;
                if (maxNumOfNodes < numOfNodes) {
                    maxNumOfNodes = numOfNodes;
                }

                m[node] = (1 + max(lftNumOfNodesTopDown, rhtNumOfNodesTopDown));
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

    int longestUnivaluePath(TreeNode* root) {
        int maxNumOfNodes = 0;

        longestUnivaluePath_Recursive(root, maxNumOfNodes);
        //longestUnivaluePath_Iterative(root, maxNumOfNodes);

        return (0 < maxNumOfNodes ? maxNumOfNodes - 1 : 0);
    }
};