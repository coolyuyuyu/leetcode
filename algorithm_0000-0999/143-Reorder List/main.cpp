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
        ListNode **ppFast = &head, **ppSlow = &head;
        while (*ppFast) {
            ppFast = &((*ppFast)->next);
            if (*ppFast) {
                ppFast = &((*ppFast)->next);
            }
            ppSlow = &((*ppSlow)->next);
        }

        ListNode *head1 = head, *head2 = *ppSlow;
        *ppSlow = nullptr;
        return {head1, head2};
    }

    ListNode* reverseList(ListNode* head) {
        ListNode **ppHead = &head;
        for (ListNode *cur = *ppHead; cur && cur->next;) {
            ListNode* nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = *ppHead;
            *ppHead = nxt;
        }

        return head;
    }

    ListNode* interleaveList(ListNode* head1, ListNode* head2) {
        ListNode *head = nullptr;
        ListNode **ppNode = &head;
        while (head1) {
            *ppNode = head1;
            head1 = head1->next;
            ppNode = &((*ppNode)->next);
            if (head2) {
                *ppNode = head2;
                head2 = head2->next;
                ppNode = &((*ppNode)->next);
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
