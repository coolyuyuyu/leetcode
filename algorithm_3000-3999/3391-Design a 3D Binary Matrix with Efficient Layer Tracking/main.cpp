class Matrix3D {
public:
    Matrix3D(int n)
        : m_mtx(n, vector<vector<bool>>(n, vector<bool>(n)))
        , m_idx2cnt(n, 0) {
        auto& indexes = m_cnt2indexes[0];
        for (int idx = 0; idx < n; ++idx) {
            indexes.insert(idx);
        }
    }

    void setCell(int x, int y, int z) {
        if (m_mtx[x][y][z]) { return; }
        m_mtx[x][y][z] = true;

        int& cnt = m_idx2cnt[x];
        m_cnt2indexes[cnt].erase(x);
        if (m_cnt2indexes[cnt].empty()) {
            m_cnt2indexes.erase(cnt);
        }
        ++cnt;
        m_cnt2indexes[cnt].insert(x);

    }

    void unsetCell(int x, int y, int z) {
        if (!m_mtx[x][y][z]) { return; }
        m_mtx[x][y][z] = false;

        int& cnt = m_idx2cnt[x];
        m_cnt2indexes[cnt].erase(x);
        if (m_cnt2indexes[cnt].empty()) {
            m_cnt2indexes.erase(cnt);
        }
        --cnt;
        m_cnt2indexes[cnt].insert(x);
    }

    int largestMatrix() {
        const auto& [_, indexes] = *(m_cnt2indexes.rbegin());
        return *(indexes.crbegin());
    }

private:
    vector<vector<vector<bool>>> m_mtx;
    vector<int> m_idx2cnt;
    map<int, set<int>> m_cnt2indexes;
};

/**
 * Your Matrix3D object will be instantiated and called as such:
 * Matrix3D* obj = new Matrix3D(n);
 * obj->setCell(x,y,z);
 * obj->unsetCell(x,y,z);
 * int param_3 = obj->largestMatrix();
 */
