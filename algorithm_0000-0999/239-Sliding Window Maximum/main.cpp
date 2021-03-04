template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class MaxStack {
public:
    explicit MaxStack(const Compare& comp = Compare())
        : m_comp(comp) {
    }

    void clear() {
        m_elems.clear();
        m_indexes.clear();
    }

    void swap(MaxStack<T>& rhs) {
        std::swap(m_elems, rhs.m_elems);
        std::swap(m_indexes, rhs.m_indexes);
    }

    void push(const T& val) {
        m_elems.push_back(val);
        if (m_indexes.empty()
            || m_comp(m_elems[m_indexes.back()], m_elems.back())
            || !m_comp(m_elems.back(), m_elems[m_indexes.back()])) {
            m_indexes.push_back(m_elems.size() - 1);
        }
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_elems.emplace_back(args...);
        if (m_indexes.empty()
            || m_comp(m_elems[m_indexes.back()], m_elems.back())
            || !m_comp(m_elems.back(), m_elems[m_indexes.back()])) {
            m_indexes.push_back(m_elems.size() - 1);
        }
    }

    void pop() {
        //assert(!empty());
        if (m_elems.size() == (m_indexes.back() + 1)) {
            m_indexes.pop_back();
        }
        m_elems.pop_back();
    }

    void pop_max() {
        size_t maxIndex = m_indexes.back();
        m_indexes.pop_back();

        Container buf(m_elems.size() - maxIndex - 1);
        std::move(m_elems.begin() + maxIndex + 1, m_elems.end(), buf.begin());

        m_elems.erase(m_elems.begin() + maxIndex, m_elems.end());

        for (const T& elem: buf) {
            push(elem);
        }
    }

    const T& top() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).top();
    }

    const T& top() const {
        //assert(!empty());
        return m_elems.back();
    }

    const T& max() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).max();
    }

    const T& max() const {
        //assert(!empty());
        return m_elems[m_indexes.back()];
    }

    bool empty() const {
        //assert(m_elems.empty() == m_indexes.empty());
        return m_elems.empty();
    }

    size_t size() const {
        return m_elems.size();
    }

private:
    Container m_elems;
    std::vector<size_t> m_indexes;
    Compare m_comp;
};

template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class MaxQueue {
public:
    explicit MaxQueue(const Compare& comp = Compare())
        : m_stkI(comp)
        , m_stkO(comp) {
    }

    void clear() {
        m_stkI.clear();
        m_stkO.clear();
    }

    void swap(MaxQueue<T>& rhs) {
        std::swap(m_stkI, rhs.m_stkI);
        std::swap(m_stkO, rhs.m_stkO);
    }

    void push(const T& v) {
        m_stkI.push(v);
    }

    template <class... Args>
    void emplace(Args&&... args) {
        m_stkI.emplace(args...);
    }

    void pop() {
        //assert(!empty());
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        m_stkO.pop();
    }

    const T& front() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).front();
    }

    const T& front() const {
        //assert(!empty());
        if (m_stkO.empty()) {
            while (!m_stkI.empty()) {
                m_stkO.push(m_stkI.top());
                m_stkI.pop();
            }
        }

        return m_stkO.top();
    }

    const T& max() {
        return static_cast<typename std::remove_reference<decltype(*this)>::type const&>(*this).max();
    }

    const T& max() const {
        //assert(!empty());
        if (m_stkI.empty()) {
            //assert(!m_stkO.empty());
            return m_stkO.max();
        }
        else {
            if (m_stkO.empty()) {
                return m_stkI.max();
            }
            else {
                return std::max(m_stkI.max(), m_stkO.max());
            }
        }
    }

    bool empty() const {
        return (m_stkI.empty() && m_stkO.empty());
    }

    size_t size() const {
        return (m_stkI.size() + m_stkO.size());
    }

private:
    MaxStack<T, Container, Compare> m_stkI;
    MaxStack<T, Container, Compare> m_stkO;
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