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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pHead = nullptr;
        ListNode** ppCur = &pHead;
        while (l1 && l2) {
            ListNode** ppNode = &(l1->val <= l2->val ? l1 : l2);
            *ppCur = *ppNode;
            *ppNode = (*ppNode)->next;

            ppCur = &((*ppCur)->next);
        }
        *ppCur = (l1 ? l1 : l2);

        return pHead;
    }
};