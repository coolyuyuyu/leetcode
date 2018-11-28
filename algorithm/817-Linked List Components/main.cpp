/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents1(ListNode* head, vector<int>& G) {
        unordered_set<int> vals;
        for (int val : G) {
            vals.insert(val);
        }

        int ans = 0;
        while (head) {
            if (vals.count(head->val) && (head->next == nullptr || !vals.count(head->next->val))) {
                ++ans;
            }

            head = head->next;
        }

        return ans;
    }

    int numComponents2(ListNode* head, vector<int>& G) {
        unordered_set<int> vals;
        for (int val : G) {
            vals.insert(val);
        }

        bool flag = false;
        int ans = 0;
        while (head) {
            if (vals.count(head->val)) {
                if (head->next == nullptr) {
                    ++ans;
                }
                flag = true;
            }
            else {
                if (flag) {
                    ++ans;
                }
                flag = false;
            }

            head = head->next;
        }

        return ans;
    }

    int numComponents(ListNode* head, vector<int>& G) {
        //return numComponents1(head, G);
        return numComponents2(head, G);
    }
};