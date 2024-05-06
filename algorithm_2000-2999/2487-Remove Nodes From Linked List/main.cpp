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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stk;
        for (ListNode* node = head; node; node = node->next) {
            while (!stk.empty() && stk.back()->val < node->val) {
                stk.pop_back();
            }
            stk.push_back(node);
        }

        head = nullptr;
        ListNode** ppCur = &head;
        for (ListNode* node : stk) {
            *ppCur = node;
            ppCur = &((*ppCur)->next);
        }
        *ppCur = nullptr;

        return head;
    }
};
