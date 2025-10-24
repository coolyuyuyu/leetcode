class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) { continue; }
            m_data.emplace_back(i, nums[i]);
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ret = 0;
        for (int i = 0, j = 0; i < m_data.size() && j < vec.m_data.size();) {
            if (m_data[i].first < vec.m_data[j].first) {
                ++i;
            }
            else if (m_data[i].first == vec.m_data[j].first) {
                ret += m_data[i++].second * vec.m_data[j++].second;
            }
            else {
                ++j;
            }
        }
        return ret;
    }

private:
    vector<pair<int, int>> m_data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
