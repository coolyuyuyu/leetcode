class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        size_t n = A.size() / 2;
        for (size_t i = 0; i < n; ++i) {
            if (0 < A[i * 2]) {
                m_data.emplace(A[i * 2], A[i * 2 + 1]);
            }
        }
    }

    int next(int n) {
        while (!m_data.empty() && 0 < n) {
            if (m_data.front().first < n) {
                n -=  m_data.front().first;
                m_data.pop();
            }
            else {
                m_data.front().first -= n;
                n = 0;
            }
        }

        return m_data.empty() ? -1 : m_data.front().second;
    }

private:
    queue<pair<int, int>> m_data;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */