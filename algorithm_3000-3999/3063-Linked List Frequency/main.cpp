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
    ListNode* frequenciesOfElements(ListNode* head) {
        ListNode* pRet = nullptr;

        unordered_map<int, ListNode*> val2node;
        for (ListNode* node = head; node; node = node->next) {
            if (val2node[node->val] == nullptr) {
                pRet = new ListNode(0, pRet);
                val2node[node->val] = pRet;
            }
            val2node[node->val]->val += 1;
        }

        return pRet;
    }
};
