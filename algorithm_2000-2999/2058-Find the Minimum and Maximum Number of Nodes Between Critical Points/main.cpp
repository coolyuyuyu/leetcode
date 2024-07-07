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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int preVal = head->val;
        int preCriticalIdx = -1;
        int fstCriticalIdx = -1;
        int idx = 1;
        int minDistance = INT_MAX, maxDistance;
        for (ListNode* node = head->next; node->next; node = node->next, ++idx) {
            int curVal = node->val;
            int nxtVal = node->next->val;
            if ((preVal > curVal && curVal < nxtVal) || (preVal < curVal && curVal > nxtVal)) {
                if (fstCriticalIdx != -1) {
                    maxDistance = idx - fstCriticalIdx;
                }
                else {
                    fstCriticalIdx = idx;
                }
                if (preCriticalIdx != -1) {
                    minDistance = std::min(minDistance, idx - preCriticalIdx);
                }

                preCriticalIdx = idx;
            }

            preVal = curVal;
        }
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        return {minDistance, maxDistance};
    }
};
