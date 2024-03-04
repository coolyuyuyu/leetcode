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
    ListNode* mergeNodes(ListNode* head) {
        ListNode** ppMerged = &head;
        while (*ppMerged) {
            ListNode* pNode = (*ppMerged)->next;
            while (pNode && pNode->val != 0) {
                (*ppMerged)->val += pNode->val;
                pNode = pNode->next;
            }
            if (!pNode) {
                (*ppMerged) = nullptr;
            }
            else {
                (*ppMerged)->next = pNode;
                ppMerged = &((*ppMerged)->next);
            }
        }

        return head;
    }
};
