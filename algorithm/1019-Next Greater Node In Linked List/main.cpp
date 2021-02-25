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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nexts;

        stack<pair<int, int>> stk; // val, index
        int size = 0;
        for (ListNode* pCur = head; pCur; pCur = pCur->next, ++size) {
            while (!stk.empty() && stk.top().first < pCur->val) {
                if (nexts.size() <= stk.top().second) {
                    nexts.resize(stk.top().second + 1, 0);
                }
                nexts[stk.top().second] = pCur->val;
                stk.pop();
            }
            stk.emplace(pCur->val, size);
        }
        if (nexts.size() < size) {
            nexts.resize(size);
        }

        return nexts;
    }
};