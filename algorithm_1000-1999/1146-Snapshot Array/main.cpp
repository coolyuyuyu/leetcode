class SnapshotArray {
public:
    SnapshotArray(int length)
        : m_snapId(0)
        , m_snaps(length, {{-1, 0}}) {
    }

    void set(int index, int val) {
        if (m_snaps[index].back().second != val) {
            m_snaps[index].emplace_back(m_snapId, val);
        }
    }

    int snap() {
        return m_snapId++;
    }

    int get(int index, int snapId) {
        const vector<pair<int, int>>& pairs = m_snaps[index];
        auto itr = std::upper_bound(pairs.begin(), pairs.end(), make_pair(snapId, INT_MAX));
        return std::prev(itr)->second;
    }

private:
    int m_snapId;
    vector<vector<pair<int, int>>> m_snaps;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
