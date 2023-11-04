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
        ListNode** ppNode = &head;
        while (list1 && list2) {
            auto& list = (list1->val < list2->val ? list1 : list2);
            *ppNode = list;
            list = list->next;
            ppNode = &((*ppNode)->next);
        }
        *ppNode = (list1 ? list1 : list2);

        return head;
    }
};
