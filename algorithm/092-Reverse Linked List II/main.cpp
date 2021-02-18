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
    ListNode* reverseList(ListNode* head, int k) {
        if (k == 0) {
            return head;
        }

        ListNode* pTail = head;

        ListNode* pPre = nullptr;
        ListNode* pCur = head;
        while (pCur && k-- > 0) {
            ListNode* pNxt = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNxt;
        }

        pTail->next = pCur;

        return pPre;
    }

    ListNode* reverseBetween_v1(ListNode* head, int m, int n) {
        ListNode** ppHead = &head;
        while (--n && (--m > 0)) {
            ppHead = &((*ppHead)->next);
        }
        assert(*ppHead);

        *ppHead = reverseList(*ppHead, n - m + 1);
        return head;
    }

    ListNode* reverseBetween_v2(ListNode* head, int m, int n) {
        ListNode** ppHead = &head;
        while (--n && (--m > 0)) {
            ppHead = &((*ppHead)->next);
        }
        assert(*ppHead);

        ListNode* pNode = *ppHead;
        while (pNode->next && n-- > 0) {
            ListNode* pTmp = pNode->next;
            pNode->next = pTmp->next;
            pTmp->next = *ppHead;
            (*ppHead) = pTmp;
        }
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        assert(m <= n);

        //return reverseBetween_v1(head, m, n);
        return reverseBetween_v2(head, m, n);
    }
};