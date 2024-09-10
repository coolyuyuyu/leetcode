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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (ListNode** ppNode = &head; *ppNode && (*ppNode)->next;) {
            int val = std::gcd((*ppNode)->val, (*ppNode)->next->val);
            ListNode* pInserted = new ListNode(val, (*ppNode)->next);
            (*ppNode)->next = pInserted;
            ppNode = &(pInserted->next);
        }

        return head;
    }
};
