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

class Strategy {
public:
    virtual int getRandom(ListNode* head) = 0;
};

class TwoPassSampling : public Strategy {
public:
    int getRandom(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        return nodes[rand() % nodes.size()]->val;
    }
};

class ReservoirSampling : public Strategy {
public:
    int getRandom(ListNode* head) {
        return getRandom(head, 1)[0];
    }

private:
    vector<int> getRandom(ListNode* head, int k) {
        vector<int> vals(k);

        for (int i = 0; i < k; ++i, head = head->next) {
            vals[i] = head->val;
        }

        for (int i = k; head; ++i, head = head->next) {
            int j = rand() % (i + 1);
            if (j < k) {
                vals[j] = head->val;
            }
        }

        return vals;
    }
};

// [a]
// P1 = a

// [a,b]
// P2 = 1/2a + 1/2b

// [a,b,c]
// P3 = 1/3a + 1/3b + 1/3c
//    = 2/3(x2) + 1/3c

class Solution {
public:
    Solution(ListNode* head)
        : m_head(head) {
        //m_strategy = new TwoPassSampling();
        m_strategy = new ReservoirSampling();
    }

    int getRandom() {
        return m_strategy->getRandom(m_head);
    }

private:
    ListNode* m_head;
    Strategy* m_strategy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
