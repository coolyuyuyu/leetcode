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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> vals(G.begin(), G.end());

        int num = 0;
        for (ListNode* pCur = head; pCur; pCur = pCur->next) {
            if (vals.find(pCur->val) != vals.end()) {
                if (!(pCur->next) || vals.find(pCur->next->val) == vals.end()) {
                    ++num;
                }
            }
        }

        return num;
    }
};