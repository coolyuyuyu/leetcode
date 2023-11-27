class SnapshotArray {
public:
    SnapshotArray(int length)
        : m_id(0)
        , m_arrs(length, {{-1, 0}}){
    }

    void set(int index, int val) {
        auto& arr = m_arrs[index];
        if (arr.back().first == m_id) {
            arr.back().second = val;
        }
        else if (arr.back().second != val) {
            arr.emplace_back(m_id, val);
        }
    }

    int snap() {
        return m_id++;
    }

    int get(int index, int snap_id) {
        const auto& arr = m_arrs[index];
        auto itr = std::upper_bound(arr.begin(), arr.end(), pair<int, int>{snap_id, INT_MAX});
        return std::prev(itr)->second;
    }

private:
    int m_id;
    vector<vector<pair<int, int>>> m_arrs;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
