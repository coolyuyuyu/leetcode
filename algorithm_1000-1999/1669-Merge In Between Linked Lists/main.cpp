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
        ListNode **ppNode1 = &list1;
        for (int i = a; 0 < i--;) {
            ppNode1 = &((*ppNode1)->next);
        }
        ListNode **ppBgn1 = ppNode1;
        for (int i = b - a + 1; 0 < i--;) {
            ppNode1 = &((*ppNode1)->next);
        }
        ListNode **ppEnd1 = ppNode1;

        ListNode** ppNode2 = &list2;
        while (*ppNode2) {
            ppNode2 = &((*ppNode2)->next);
        }

        *ppBgn1 = list2;
        *ppNode2 = *ppEnd1;

        return list1;
    }
};
