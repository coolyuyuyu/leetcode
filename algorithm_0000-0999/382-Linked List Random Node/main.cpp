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
    Solution(ListNode* head)
        : m_head(head) {
    }

    int getRandom() {
        // reservoir sampling

        int ret;

        int i = 0;
        for (ListNode* node = m_head; node; node = node->next) {
            if (std::rand() % ++i == 0) {
                ret = node->val;
            }
        }

        return ret;
    }

private:
    ListNode* m_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
