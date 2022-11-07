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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pHead = nullptr;
        ListNode** ppCur = &pHead;
        while (list1 && list2) {
            ListNode*& pNode = list1->val < list2->val ? list1 : list2;
            *ppCur = pNode;
            ppCur = &(pNode->next);
            pNode = pNode->next;
        }
        *ppCur = list1 ? list1 : list2;

        return pHead;
    }
};
