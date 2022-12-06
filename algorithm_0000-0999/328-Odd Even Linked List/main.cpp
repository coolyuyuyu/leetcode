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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* pHead1 = nullptr;
        ListNode* pHead2 = nullptr;
        ListNode** ppCurs[2] = {&pHead1, &pHead2};
        for (int i = 0; head; i ^= 1, head = head->next) {
            *(ppCurs[i]) = head;
            ppCurs[i] = &((*(ppCurs[i]))->next);
        }
        *(ppCurs[0]) = pHead2;
        *(ppCurs[1]) = nullptr;

        return pHead1;
    }
};
