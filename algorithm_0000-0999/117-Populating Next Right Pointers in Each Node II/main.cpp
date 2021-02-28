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

    void connect_1(TreeLinkNode *pRoot) {
        while (pRoot) {
            TreeLinkNode* pChildHead = NULL;
            TreeLinkNode** ppChildHead = &pChildHead;
            for (TreeLinkNode* pParent = pRoot; pParent; pParent = pParent->next) {
                TreeLinkNode* pChildLft = pParent->left;
                if (pChildLft) {
                    *ppChildHead = pChildLft;
                    ppChildHead = &(pChildLft->next);
                }
                TreeLinkNode* pChildRht = pParent->right;
                if (pChildRht) {
                    *ppChildHead = pChildRht;
                    ppChildHead = &(pChildRht->next);
                }
            }

            pRoot = pChildHead;
        }
    }
};