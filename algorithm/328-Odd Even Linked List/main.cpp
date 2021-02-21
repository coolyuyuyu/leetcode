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
        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;
        ListNode** ppCurPair[2] = {&head1, &head2};

        size_t index = 0;
        for (ListNode* pCur = head; pCur; pCur = pCur->next, index ^= 1) {
            *(ppCurPair[index]) = pCur;
            ppCurPair[index] =  &((*(ppCurPair[index]))->next);
        }
        *(ppCurPair[0]) = head2;
        *(ppCurPair[1]) = nullptr;

        return head1;
    }
};