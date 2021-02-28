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
        unordered_map<int, ListNode**> m;

        int sum = 0;
        for (ListNode** ppCur = &head; *ppCur; ppCur = &((*ppCur)->next)) {
            auto itr = m.find(sum);
            if (itr != m.end()) {
                ListNode** ppPrev = itr->second;
                int tmpSum = sum + (*ppPrev)->val;
                for (ListNode** ppDel = &((*ppPrev)->next); ppDel != ppCur; ppDel = &((*ppDel)->next)) {
                    m.erase(tmpSum);
                    tmpSum += (*ppDel)->val;
                }
                *ppPrev = *ppCur;
            }
            else {
                m.emplace(sum, ppCur);
            }

            sum += (*ppCur)->val;
        }

        auto itr = m.find(sum);
        if (itr != m.end()) {
            ListNode** ppPrev = itr->second;
            *ppPrev = nullptr;
        }

        return head;
    }
};