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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode* pRet = nullptr;
        ListNode** ppNode = &pRet;
        for (; head; head = head->next) {
            if (s.find(head->val) == s.end()) {
                *ppNode = head;
                ppNode = &((*ppNode)->next);
            }
        }
        *ppNode = nullptr;

        return pRet;
    }
};
