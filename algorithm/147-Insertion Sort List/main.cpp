/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* pSortedHead = NULL;
        while (head) {
            ListNode* pNode = head;
            head = head->next;

            ListNode** ppSortedCur = &pSortedHead;
            while (*ppSortedCur && (*ppSortedCur)->val < pNode->val) {
                ppSortedCur = &((*ppSortedCur)->next);
            }

            pNode->next = (*ppSortedCur);
            *ppSortedCur = pNode;
        }

        return pSortedHead;
    }
};