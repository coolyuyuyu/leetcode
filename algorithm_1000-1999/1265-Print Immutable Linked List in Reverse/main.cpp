/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    // Time: O(n), Space: O(n)
    void byDFS(ImmutableListNode* head) {
        std::function<void(ImmutableListNode*)> f = [&](ImmutableListNode* head) {
            if (!head) { return; }
            f(head->getNext());
            head->printValue();
        };
        f(head);
    }

    // Time: O(n), Space: O(sqrt(n))
    void bySquareRootDecomposition(ImmutableListNode* head) {
        int len = 0;
        for (ImmutableListNode* p = head; p; p = p->getNext()) {
            ++len;
        }

        std::function<void(ImmutableListNode*, int)> f = [&](ImmutableListNode* head, int len) {
            if (!head || len == 0) { return; }
            f(head->getNext(), --len);
            head->printValue();
        };

        int bktSize = std::sqrt(len);
        stack<ImmutableListNode*> stk;
        ImmutableListNode* p = head;
        for (int i = 0; i < len; ++i, p = p->getNext()) {
            if ((i % bktSize)== 0) {
                cout << i << endl;
                stk.push(p);
            }
        }

        for (; !stk.empty(); stk.pop()) {
            f(stk.top(), bktSize);
        }
    }

    void printLinkedListInReverse(ImmutableListNode* head) {
        //return byDFS(head);
        return bySquareRootDecomposition(head);
    }
};
