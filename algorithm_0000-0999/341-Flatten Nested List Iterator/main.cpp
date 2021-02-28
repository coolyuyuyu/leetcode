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
    NestedIterator(vector<NestedInteger> &nestedList) {
        m_stk.push(pair<const vector<NestedInteger>&, size_t>(nestedList, 0));
    }

    int next() {
        pair<const vector<NestedInteger>&, size_t>& p = m_stk.top();
        int ret = p.first[p.second].getInteger();
        p.second += 1;
        return ret;
    }

    bool hasNext() {
        while (m_stk.empty() == false) {
            const pair<const vector<NestedInteger>&, size_t>& p = m_stk.top();
            const vector<NestedInteger>& nestedList = p.first;
            const size_t index = p.second;
            if (index < nestedList.size()) {
                const NestedInteger& nestedInt = nestedList[index];
                if (nestedInt.isInteger()) {
                    return true;
                }
                else {
                    m_stk.push(pair<const vector<NestedInteger>&, size_t>(nestedInt.getList(), 0));
                }
            }
            else {
                m_stk.pop();
                if (m_stk.empty() == false) {
                    m_stk.top().second += 1;
                }
            }
        }

        return false;
    }

private:
    stack<pair<const vector<NestedInteger>&, size_t>> m_stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */