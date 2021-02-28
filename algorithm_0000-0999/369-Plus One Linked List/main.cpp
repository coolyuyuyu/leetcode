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
    // Time: O(n), Space: O(n)
    ListNode* plusOne_v1(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* pCur = head;
        while (pCur) {
            stk.push(pCur);
            pCur = pCur->next;
        }

        bool carry = true;
        while (!stk.empty()) {
            pCur = stk.top();
            stk.pop();
            if (carry) {
                if (pCur->val == 9) {
                    pCur->val = 0;
                }
                else {
                    carry = false;
                    ++pCur->val;
                }
            }

            if (!carry) {
                return head;
            }
        }

        if (carry) {
            pCur = new ListNode(1);
            pCur->next = head;
            head = pCur;
        }

        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode** ppHead = &head;
        ListNode* pNode = *ppHead;
        while (pNode->next) {
            ListNode* pTmp = pNode->next;
            pNode->next= pTmp->next;
            pTmp->next = *ppHead;
            *ppHead = pTmp;
        }

        return head;
    }

    // Time: O(n), Space: O(1)
    ListNode* plusOne_v2(ListNode* head) {
        head = reverseList(head);

        bool carry = true;
        for (ListNode** ppNode = &head; carry; ppNode = &((*ppNode)->next)) {
            if (!(*ppNode)) {
                *ppNode = new ListNode(1);
            }
            else {
                (*ppNode)->val += 1;
            }

            carry = (10 <= (*ppNode)->val);
            (*ppNode)->val = (*ppNode)->val % 10;
        }

        return reverseList(head);
    }

    ListNode* plusOne(ListNode* head) {
        //return plusOne_v1(head);
        return plusOne_v2(head);
    }
};