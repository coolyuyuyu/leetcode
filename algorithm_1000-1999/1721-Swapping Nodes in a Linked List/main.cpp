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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode** ppForeward;
        ListNode** ppBackward;
        {
            ListNode** ppFast = &head;
            for (int i = 1; i < k; ++i) {
                ppFast = &((*ppFast)->next);
            }
            ppForeward = ppFast;

            ListNode** ppSlow = &head;
            while ((*ppFast)->next) {
                ppSlow = &((*ppSlow)->next);
                ppFast = &((*ppFast)->next);
            }
            ppBackward = ppSlow;

        }
        swap(*ppForeward, *ppBackward);
        swap((*ppForeward)->next, (*ppBackward)->next);

        return head;
    }
};