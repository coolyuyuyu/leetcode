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
    string gameResult(ListNode* head) {
        int ePoints = 0, oPoints = 0;
        for (ListNode* node = head; node; node = node->next->next) {
            int eScore = node->val, oScore = node->next->val;
            if (eScore > oScore) {
                ++ePoints;
            }
            else if (eScore < oScore) {
                ++oPoints;
            }
        }

        if (ePoints > oPoints) {
            return "Even";
        }
        else if (ePoints == oPoints) {
            return "Tie";
        }
        else {
            return "Odd";
        }
    }
};
