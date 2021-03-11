/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        Node* pHeadOld = root;
        Node** ppCurOld = &pHeadOld;
        NodeCopy* pHeadNew = nullptr;
        NodeCopy** ppCurNew = &pHeadNew;

        map<Node*, NodeCopy*> m;

        stack<pair<Node**, NodeCopy**>> stk;
        if (*ppCurOld) {
            stk.emplace(ppCurOld, ppCurNew);
        }
        while (!stk.empty()) {
            ppCurOld = stk.top().first;
            ppCurNew = stk.top().second;
            stk.pop();

            auto p = m.insert({*ppCurOld, nullptr});
            if (p.second) {
                p.first->second = new NodeCopy((*ppCurOld)->val);
            }
            *ppCurNew = p.first->second;

            if ((*ppCurOld)->random) {
                auto p = m.insert({(*ppCurOld)->random, nullptr});
                if (p.second) {
                    p.first->second = new NodeCopy((*ppCurOld)->random->val);
                }
                (*ppCurNew)->random = p.first->second;
            }

            if ((*ppCurOld)->right) {
                stk.emplace(&((*ppCurOld)->right), &((*ppCurNew)->right));
            }
            if ((*ppCurOld)->left) {
                stk.emplace(&((*ppCurOld)->left), &((*ppCurNew)->left));
            }
        }

        return pHeadNew;
    }
};