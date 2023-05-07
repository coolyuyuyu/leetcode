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
        ListNode* head = nullptr;
        ListNode** ppCur = &head;
        while (list1 && list2) {
            ListNode*& node = (list1->val < list2->val ? list1 : list2);
            *ppCur = node;

            ppCur = &(node->next);
            node = node->next;
        }
        *ppCur = list1 ? list1 : list2;

        return head;
    }
};
