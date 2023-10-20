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

class IStrategy {
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
};

class FwdScanStrategy : public IStrategy{
public:
    FwdScanStrategy(vector<NestedInteger>& nestedList) {
        m_stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        return (m_stk.top().first++)->getInteger();
    }

    bool hasNext() {
        while (!m_stk.empty()) {
            auto& [itr, end] = m_stk.top();
            if (itr == end) {
                m_stk.pop();
            }
            else {
                if (itr->isInteger()) {
                    return true;
                }
                else {
                    const vector<NestedInteger>& nl = itr++->getList();
                    m_stk.emplace(nl.begin(), nl.end());
                }
            }
        }

        return false;
    }

private:
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> m_stk;
};

class BwdScanStrategy : public IStrategy{
public:
    BwdScanStrategy(vector<NestedInteger>& nestedList) {
        for (int i = nestedList.size(); 0 < i--;) {
            m_stk.push(nestedList[i]);
        }
    }

    int next() {
        int ret = m_stk.top().getInteger();
        m_stk.pop();
        return ret;
    }

    bool hasNext() {
        while (!m_stk.empty()) {
            if (m_stk.top().isInteger()) {
                return true;
            }

            vector<NestedInteger> nl = m_stk.top().getList();
            m_stk.pop();
            for (int i = nl.size(); 0 < i--;) {
                m_stk.push(nl[i]);
            }
        }

        return false;
    }

private:
    stack<NestedInteger> m_stk;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList)
        //: m_strategy(new FwdScanStrategy(nestedList)) {
        : m_strategy(new BwdScanStrategy(nestedList)) {
    }

    int next() {
        return m_strategy->next();
    }

    bool hasNext() {
        return m_strategy->hasNext();
    }

private:
    IStrategy* m_strategy;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
