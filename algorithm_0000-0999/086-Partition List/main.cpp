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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pLftHead = nullptr;
        ListNode** ppLftCur = &pLftHead;
        ListNode* pRhtHead = nullptr;
        ListNode** ppRhtCur = &pRhtHead;
        for (ListNode* pCur = head; pCur; pCur = pCur->next) {
            if (pCur->val < x) {
                *ppLftCur = pCur;
                ppLftCur = &(pCur->next);
            }
            else {
                *ppRhtCur = pCur;
                ppRhtCur = &(pCur->next);
            }
        }

        *ppLftCur = pRhtHead;
        *ppRhtCur = nullptr;

        return pLftHead;
    }
};