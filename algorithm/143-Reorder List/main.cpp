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
        ListNode** ppSlow = &head;
        ListNode** ppFast = &head;
        while (*ppFast) {
            ppSlow = &((*ppSlow)->next);
            ppFast = &((*ppFast)->next);
            if (*ppFast) {
                ppFast = &((*ppFast)->next);
            }
        }
        pair<ListNode*, ListNode*> p = {head, *ppSlow};
        *ppSlow = nullptr;

        return p;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode** ppHead = &head;
        ListNode* pNode = *ppHead;
        while (pNode->next) {
            ListNode* pTmp = pNode->next;
            pNode->next = pTmp->next;
            pTmp->next = *ppHead;
            *ppHead = pTmp;
        }

        return *ppHead;
    }

    void reorderList(ListNode* head) {
        pair<ListNode*, ListNode*> p = splitList(head);
        ListNode* head1 = p.first;
        ListNode* head2 = p.second;

        head2 = reverseList(head2);

        while (head1 && head2) {
            ListNode *pTmp = head2;
            head2 = head2->next;
            pTmp->next = head1->next;
            head1->next = pTmp;
            head1 = pTmp->next;
        }
    }
};