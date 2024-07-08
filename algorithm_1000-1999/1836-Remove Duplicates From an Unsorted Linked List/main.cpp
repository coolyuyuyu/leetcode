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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> cnts;
        for (ListNode* node = head; node; node = node->next) {
            ++cnts[node->val];
        }

        ListNode* pRet = nullptr;
        for (ListNode** ppNode = &head; *ppNode;) {
            if (cnts[(*ppNode)->val] > 1) {
                ListNode* pDel = *ppNode;
                *ppNode = (*ppNode)->next;
            }
            else {
                ppNode = &((*ppNode)->next);
            }
        }

        return head;
    }
};
