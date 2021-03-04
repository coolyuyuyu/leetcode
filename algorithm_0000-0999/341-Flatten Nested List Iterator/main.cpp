/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList)
        : m_itr(nestedList.cbegin())
        , m_end(nestedList.cend()) {
    }

    int next() {
        int val = m_itr->getInteger();
        ++m_itr;
        return val;
    }

    bool hasNext() {
        while (true) {
            if (m_itr == m_end) {
                if (m_stk.empty()) {
                    return false;
                }
                else {
                    m_itr = m_stk.top().first;
                    m_end = m_stk.top().second;
                    m_stk.pop();
                    ++m_itr;
                }
            }
            else {
                if (m_itr->isInteger()) {
                    return true;
                }
                else {
                    m_stk.emplace(m_itr, m_end);

                    const vector<NestedInteger>& nestedList = m_itr->getList();
                    m_itr = nestedList.cbegin();
                    m_end = nestedList.cend();
                }
            }
        }
    }

private:
    vector<NestedInteger>::const_iterator m_itr, m_end;
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> m_stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */