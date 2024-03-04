class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        m_n = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]  == 0) {
                continue;
            }
            m_vals.emplace_back(i, nums[i]);
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ret = 0;
        for (int i = 0, j = 0; i < m_vals.size() && j < vec.m_vals.size();) {
            if (m_vals[i].first < vec.m_vals[j].first) {
                ++i;
            }
            else if (m_vals[i].first == vec.m_vals[j].first) {
                ret += m_vals[i].second * vec.m_vals[j].second;
                ++i, ++j;
            }
            else {
                ++j;
            }
        }

        return ret;
    }

private:
    int m_n;
    vector<pair<int, int>> m_vals;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
