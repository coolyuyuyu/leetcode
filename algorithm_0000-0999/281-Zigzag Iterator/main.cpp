class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if (!v1.empty()) {
            m_iterPairs.push(make_pair(v1.begin(), v1.end()));
        }
        if (!v2.empty()) {
            m_iterPairs.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        pair<vector<int>::const_iterator, vector<int>::const_iterator> iterPair = m_iterPairs.front();
        m_iterPairs.pop();

        int val = *(iterPair.first);
        ++iterPair.first;
        if (iterPair.first != iterPair.second) {
            m_iterPairs.push(iterPair);
        }

        return val;
    }

    bool hasNext() {
        return !m_iterPairs.empty();
    }

private:
    queue<pair<vector<int>::const_iterator, vector<int>::const_iterator>> m_iterPairs;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */