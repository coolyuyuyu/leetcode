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
    ListNode* reverseList_v1(ListNode* head) {
        ListNode* pre = nullptr;
        for (ListNode* cur = head; cur;) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }

    ListNode* reverseList_v2(ListNode* head) {
        ListNode** ppHead = &head;
        for (ListNode* pCur = *ppHead; pCur && pCur->next;) {
            ListNode* pNxt = pCur->next;
            pCur->next = pNxt->next;
            pNxt->next = *ppHead;
            *ppHead = pNxt;
        }

        return head;
    }

    ListNode* reverseList(ListNode* head) {
        //return reverseList_v1(head);
        return reverseList_v2(head);
    }
};
