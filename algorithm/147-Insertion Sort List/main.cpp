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
    ListNode* insertionSortList_v1(ListNode* head) {
        ListNode* headNew = nullptr;
        while (head) {
            ListNode* pNode = head;
            head = head->next;

            ListNode** ppSortedCur = &headNew;
            while (*ppSortedCur && (*ppSortedCur)->val < pNode->val) {
                ppSortedCur = &((*ppSortedCur)->next);
            }
            pNode->next = *ppSortedCur;
            *ppSortedCur = pNode;
        }

        return headNew;
    }

    // Record the last sorted element. Speedup for alreay/nearly sorted case.
    ListNode* insertionSortList_v2(ListNode* head) {
        ListNode* headNew = nullptr;
        ListNode* pSortedTail = nullptr;
        while (head) {
            ListNode* pNode = head;
            head = head->next;

            if (pSortedTail && pSortedTail->val <= pNode->val) {
                pSortedTail->next = pNode;
                pSortedTail = pNode;
                pNode->next = nullptr;
            }
            else {
                ListNode** ppSortedCur = &headNew;
                while (*ppSortedCur && (*ppSortedCur)->val < pNode->val) {
                    ppSortedCur = &((*ppSortedCur)->next);
                }
                if (*ppSortedCur == nullptr) {
                    pSortedTail = pNode;
                }
                pNode->next = *ppSortedCur;
                *ppSortedCur = pNode;
            }
        }

        return headNew;
    }

    ListNode* insertionSortList(ListNode* head) {
        //return insertionSortList_v1(head);
        return insertionSortList_v2(head);
    }
};