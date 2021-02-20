/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Time: O(n), Space: O(n)
    Node* copyRandomList_v1(Node* head) {
        Node* headNew = nullptr;
        Node** ppCurNew = &headNew;

        unordered_map<Node*, Node*> m;
        for (Node* pCur = head; pCur; pCur = pCur->next) {
            auto p = m.emplace(pCur, nullptr);
            if (p.second) {
                p.first->second = new Node(pCur->val);
            }
            *ppCurNew = p.first->second;

            if (pCur->random) {
                auto p = m.emplace(pCur->random, nullptr);
                if (p.second) {
                    p.first->second = new Node(pCur->random->val);
                }
                (*ppCurNew)->random = p.first->second;
            }

            ppCurNew = &((*ppCurNew)->next);
        }

        return headNew;
    }

    Node* copyRandomList(Node* head) {
        return copyRandomList_v1(head);
    }
};