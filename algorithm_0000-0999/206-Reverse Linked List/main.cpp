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
    ListNode* reverseList_v1(ListNode* head) {
        ListNode* pPre = nullptr;
        ListNode* pCur = head;
        while (pCur) {
            ListNode* pNxt = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNxt;
        }

        return pPre;
    }

    ListNode* reverseList_v2(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode** ppHead = &head;
        for (ListNode* pNode = *ppHead; pNode->next;) {
            ListNode* pTmp = pNode->next;
            pNode->next = pTmp->next;
            pTmp->next = *ppHead;
            *ppHead = pTmp;

        }

        return head;
    }

    ListNode* reverseList(ListNode* head) {
        //return reverseList_v1(head);
        return reverseList_v2(head);
    }
};
