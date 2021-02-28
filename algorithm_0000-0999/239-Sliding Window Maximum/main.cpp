template <typename T>
class MaxStack {
public:
    MaxStack() {
    }

    void push(const T& val) {
        m_data.push_back(val);

        if (m_max.empty() || m_max.back() <= val) {
            m_max.push_back(val);
        }
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_data.emplace_back(args...);

        if (m_max.empty() || m_max.back() <= m_data.back()) {
            m_max.push_back(m_data.back());
        }
    }

    void pop() {
        if (m_data.back() == max()) {
            m_max.pop_back();
        }

        m_data.pop_back();
    }

    const T& top() {
        return m_data.back();
    }

    const T& top() const {
        return const_cast<MaxStack<T>*>(this)->top();
    }

    const T& max() {
        return m_max.back();
    }

    const T& max() const {
        return const_cast<MaxStack<T>*>(this)->max();
    }

    bool empty() const {
        return m_data.empty();
    }

    size_t size() const {
        return m_data.size();
    }

private:
    std::vector<T> m_data;
    std::vector<T> m_max;
};

template <typename T>
class MaxQueue {
public:
    MaxQueue () {
    }

    void push(const T& v) {
        m_stkI.push(v);
    }

    template <class... Args>
    void emplace (Args&&... args) {
        m_stkI.emplace(args...);
    }

    void pop() {
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        m_stkO.pop();
    }

    const T& front() {
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        return m_stkO.top();
    }

    const T& front() const {
        return const_cast<MaxStack<T>*>(this)->front();
    }

    const T& max() {
        if (m_stkI.empty() && m_stkO.empty()) {
            throw std::domain_error(std::string("empty"));
        }
        else if (!m_stkI.empty() && m_stkO.empty()) {
            return m_stkI.max();
        }
        else if (m_stkI.empty() && !m_stkO.empty()) {
            return m_stkO.max();
        }
        else {
            return std::max(m_stkI.max(), m_stkO.max());
        }
    }

    const T& max() const {
        return const_cast<MaxStack<T>*>(this)->max();
    }

    bool empty() const {
        return (m_stkI.empty() && m_stkO.empty());
    }

    size_t size() const {
        return (m_stkI.size() + m_stkO.size());
    }

private:
    MaxStack<T> m_stkI;
    MaxStack<T> m_stkO;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
        assert(k <= nums.size());

        vector<int> ans;
        ans.reserve(nums.size() - k + 1);

        MaxQueue<int> mq;
        for (size_t i = 0; i < k; ++i) {
            mq.push(nums[i]);
        }
        ans.emplace_back(mq.max());

        for (size_t i = k; i < nums.size(); ++i) {
            mq.push(nums[i]);
            mq.pop();
            ans.emplace_back(mq.max());
        }

        return ans;
    }
};