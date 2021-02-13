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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode** ppForeward;
        ListNode** ppBackward;
        {
            ListNode** ppFast = &list1;
            for (int i = 0; i < a; ++i) {
                ppFast = &((*ppFast)->next);
            }
            ppForeward = ppFast;

            cout << b - a << endl;
            for (int i = 0, diff = b - a + 1; i < diff; ++i) {
                ppFast = &((*ppFast)->next);
            }
            ppBackward = ppFast;
        }

        *ppForeward = list2;

        ListNode** ppNode2 = &list2;
        while (*ppNode2) {
            ppNode2 = &((*ppNode2)->next);
        }
        *ppNode2 = *ppBackward;

        return list1;
    }
};