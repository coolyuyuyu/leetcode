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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> nums(m, vector<int>(n, -1));
        for (int top = 0, btm = m - 1, lft = 0, rht = n - 1; head;) {
            for (int c = lft; c <= rht && head; ++c, head = head->next) {
                nums[top][c] = head->val;
            }
            if (++top > btm || !head) { break; }

            for (size_t r = top; r <= btm && head; ++r, head = head->next) {
                nums[r][rht] = head->val;
            }
            if (lft >= rht-- || !head) { break; }

            for (size_t c = rht + 1; lft < c-- && head; head = head->next) {
                nums[btm][c] = head->val;
            }
            if (btm-- <= top || !head) { break; }

            for (size_t r = btm + 1; top < r-- && head; head = head->next) {
                nums[r][lft] = head->val;
            }
            if (++lft > rht || !head) { break; }
        }

        return nums;
    }
};
