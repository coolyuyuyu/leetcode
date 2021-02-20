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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        int len = 0;
        ListNode** ppTail = &head;
        while (*ppTail) {
            ppTail = &((*ppTail)->next);
            ++len;
        }
        *ppTail = head;
        k = len - k % len;

        ppTail = &head;
        while (0 < k--) {
            ppTail = &((*ppTail)->next);
        }

        head = *ppTail;
        *ppTail = nullptr;

        return head;
    }
};