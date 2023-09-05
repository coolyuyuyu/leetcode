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

    // Time: O(n), Space: O(1)
    Node* copyRandomList_v2(Node* head) {
        for (Node* pCur = head; pCur; pCur = pCur->next->next) {
            Node* pNode = new Node(pCur->val, pCur->next, nullptr);
            pCur->next = pNode;
        }

        for (Node* pCur = head; pCur; pCur = pCur->next->next) {
            if (pCur->random) {
                pCur->next->random = pCur->random->next;
            }
        }

        Node* headNew = nullptr;
        Node** ppCurNew = &headNew;
        for (Node* pCur = head; pCur; pCur = pCur->next) {
            *ppCurNew = pCur->next;
            ppCurNew = &((*ppCurNew)->next);

            pCur->next = pCur->next->next;
        }

        return headNew;
    }

    // Time: O(n), Space: O(n)
    Node* copyRandomList_v3(Node* head) {
        unordered_map<Node*, Node*> cache;
        std::function<Node*(Node*)> dfs = [&](Node* p) -> Node* {
            if (!p) {
                return nullptr;
            }

            Node*& q = cache[p];
            if (q) {
                return q;
            }
            q = new Node(p->val);
            q->next = dfs(p->next);
            q->random = dfs(p->random);

            return q;
        };

        return dfs(head);
    }

    Node* copyRandomList(Node* head) {
        //return copyRandomList_v1(head);
        //return copyRandomList_v2(head);
        return copyRandomList_v3(head);
    }
};
