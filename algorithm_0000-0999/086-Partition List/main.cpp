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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1 = nullptr, *head2 = nullptr;
        ListNode **ppNode1 = &head1, **ppNode2 = &head2;
        for (ListNode* pNode = head; pNode; pNode = pNode->next) {
            if (pNode->val < x) {
                *ppNode1 = pNode;
                ppNode1 = &((*ppNode1)->next);
            }
            else {
                *ppNode2 = pNode;
                ppNode2 = &((*ppNode2)->next);
            }
        }
        *ppNode1 = head2;
        *ppNode2 = nullptr;

        return head1;
    }
};
