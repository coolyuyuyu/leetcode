class MonoQueue {
public:
    MonoQueue() {
    }

    void push(int val) {
        size_t count = 0;
        while (!m_deque.empty() && m_deque.back().first < val) {
            count += m_deque.back().second + 1;
            m_deque.pop_back();
        }

        m_deque.emplace_back(val, count);
    }

    void pop() {
        if (0 < m_deque.front().second) {
            --(m_deque.front().second);
            return;
        }

        m_deque.pop_front();
    }

    int max() {
        return m_deque.front().first;
    }

private:
    deque<pair<int, size_t>> m_deque;
};

class Solution {
public:
    vector<int> maxSlidingWindowMonoQueue(vector<int>& nums, size_t k) {
        size_t i;
        MonoQueue mq;
        for (i = 0; i + 1 < k; ++i) {
            mq.push(nums[i]);
        }

        vector<int> ans;
        for (; i < nums.size(); ++i) {
            mq.push(nums[i]);
            ans.emplace_back(mq.max());
            mq.pop();
        }

        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
        assert(k <= nums.size());

        return maxSlidingWindowMonoQueue(nums, k);
    }
};