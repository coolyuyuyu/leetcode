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
    ListNode* removeZeroSumSublists(ListNode* head) {
        head = new ListNode(0, head);

        int presum = 0;
        unordered_map<int, ListNode*> presum2node;
        for (ListNode* cur = head; cur; cur = cur->next) {
            presum += cur->val;

            auto itr = presum2node.find(presum);
            if (itr == presum2node.end()) {
                presum2node.emplace(presum, cur);
            }
            else {
                auto [_, pre] = *itr;

                int sum = presum;
                for (ListNode* node = pre->next; node != cur; node = node->next) {
                    sum += node->val;
                    presum2node.erase(sum);
                }

                pre->next = cur->next;
            }
        }

        return head->next;
    }
};
