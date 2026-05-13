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

        ListNode** ppNode = &head;
        int n = 0;
        for (; *ppNode; ++n) {
            ppNode = &((*ppNode)->next);
        }
        k = n - k % n;

        // link the tail to head
        *ppNode = head;

        // find new head
        ppNode = &head;
        while (0 < k--) {
            ppNode = &((*ppNode)->next);
        }
        head = *ppNode;

        // break link from new head to previous
        *ppNode = nullptr;

        return head;
    }
};
