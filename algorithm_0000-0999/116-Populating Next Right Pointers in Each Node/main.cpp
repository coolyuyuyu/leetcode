/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect_1(root);
    }
    void connect_0(TreeLinkNode *root) {
        queue<TreeLinkNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            TreeLinkNode* pHead = NULL;
            TreeLinkNode** ppCur = &pHead;
            for (size_t n = nodes.size(); n > 0; --n) {
                TreeLinkNode* node = nodes.front();
                nodes.pop();

                *ppCur = node;
                ppCur = &(node->next);

                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
        }
    }

    void connect_1(TreeLinkNode *root) {
        if (!root) {
            return;
        }

        for (; root->left; root = root->left) {
            TreeLinkNode* parentPre = NULL;
            for (TreeLinkNode* parentCur = root; parentCur; parentCur = parentCur->next) {
                parentCur->left->next = parentCur->right;
                if (parentCur->next) {
                    parentCur->right->next = parentCur->next->left;
                }
            }
        }
    }
};