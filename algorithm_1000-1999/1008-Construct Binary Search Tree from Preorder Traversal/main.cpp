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
    TreeNode* bstFromPreorder_Recursive(vector<int>::iterator& itr, vector<int>::iterator end, int maxVal = numeric_limits<int>::max()) {
        if (itr == end || maxVal < *itr) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(*itr++);
        root->left = bstFromPreorder_Recursive(itr, end, root->val);
        root->right = bstFromPreorder_Recursive(itr, end, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder_Iterative(vector<int>& preorder) {
        TreeNode* root = nullptr;
        TreeNode** ppNode = &root;

        stack<TreeNode*> stk;
        for (int val : preorder) {
            while (!stk.empty() && stk.top()->val < val) {
                ppNode = &(stk.top()->right);
                stk.pop();
            }

            *ppNode = new TreeNode(val);

            stk.emplace(*ppNode);

            ppNode = &((*ppNode)->left);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //vector<int>::iterator itr = preorder.begin();
        //return bstFromPreorder_Recursive(itr, preorder.end());

        return bstFromPreorder_Iterative(preorder);
    }
};