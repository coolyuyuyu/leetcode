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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode** ppCur = &head;
        while (*ppCur) {
            for (int i = 0; i < m && *ppCur; ++i) {
                ppCur = &((*ppCur)->next);
            }

            for (int i = 0; i < n && *ppCur; ++i) {
                ListNode* pDel = (*ppCur);
                *ppCur = pDel->next;
                delete pDel;
            }
        }

        return head;
    }
};