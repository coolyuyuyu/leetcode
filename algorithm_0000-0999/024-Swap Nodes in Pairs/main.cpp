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
    ListNode* swapPairs(ListNode* head) {
        for (ListNode** ppNode1 = &head; *ppNode1 && (*ppNode1)->next;) {
            ListNode** ppNode2 = &((*ppNode1)->next);
            std::swap(*ppNode1, *ppNode2);
            std::swap((*ppNode1)->next, (*ppNode2)->next);
            ppNode1 = ppNode2;
        }

        return head;
    }
};
