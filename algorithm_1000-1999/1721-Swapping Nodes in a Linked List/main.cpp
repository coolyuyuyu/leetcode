/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode **ppFwd, **ppBwd;

        ListNode **ppFast = &head;
        for (int i = 1; i < k; ++i) {
            ppFast = &((*ppFast)->next);
        }
        ppFwd = ppFast;

        ListNode **ppSlow = &head;
        while ((*ppFast)->next) {
            ppSlow = &((*ppSlow)->next);
            ppFast = &((*ppFast)->next);
        }
        ppBwd = ppSlow;

        std::swap(*ppFwd, *ppBwd);
        std::swap((*ppFwd)->next, (*ppBwd)->next);

        return head;
    }
};
