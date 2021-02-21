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

    ListNode* insertionSortList(ListNode* head) {
        return insertionSortList_v1(head);
    }
};