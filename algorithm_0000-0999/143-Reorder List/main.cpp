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
    pair<ListNode*, ListNode*> splitList(ListNode* head) {
        ListNode *pFast = head, **ppSlow = &head;
        while (pFast) {
            pFast = pFast->next;
            if (pFast) {
                pFast = pFast->next;
            }
            ppSlow = &((*ppSlow)->next);
        }

        ListNode *head1 = head;
        ListNode* head2 = *ppSlow;
        *ppSlow = nullptr;

        return {head1, head2};
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode** ppHead = &head;
        for (ListNode* pCur = *ppHead; pCur->next;) {
            ListNode* pNxt = pCur->next;
            pCur->next = pNxt->next;
            pNxt->next = *ppHead;
            *ppHead = pNxt;
        }

        return head;
    }

    ListNode* interleaveList(ListNode* head1, ListNode* head2) {
        ListNode *head = nullptr;
        ListNode **ppCur = &head;
        while(head1) {
            *ppCur = head1;
            ppCur = &(head1->next);
            head1 = head1->next;
            if (head2) {
                *ppCur = head2;
                ppCur = &(head2->next);
                head2 = head2->next;
            }
        }
        return head;
    }

    void reorderList(ListNode* head) {
        auto [head1, head2] = splitList(head);
        head2 = reverseList(head2);
        interleaveList(head1, head2);
    }
};
