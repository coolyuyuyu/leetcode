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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pHead = NULL;
        ListNode** ppCur = &pHead;
        while (l1 && l2) {
            ListNode** ppNode = l1->val < l2->val ? &l1 : &l2;
            *ppCur = *ppNode;
            *ppNode = (*ppNode)->next;

            ppCur = &((*ppCur)->next);
        }

        *ppCur = l1 ? l1 : l2;

        return pHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        for (size_t iteration = ceil(log2(lists.size())), space = 1; iteration > 0; --iteration, space *= 2) {
            size_t step = space * 2;
            for (size_t i = 0; i + space < lists.size(); i += step) {
                lists[i] = mergeTwoLists(lists[i], lists[i + space]);
            }
        }

        return lists.front();
    }
};