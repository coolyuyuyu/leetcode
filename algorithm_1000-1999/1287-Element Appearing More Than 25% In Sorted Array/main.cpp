class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // 25%, 50%, 75%
        for (size_t i = 1; i < 4; ++i) {
            int val = arr[arr.size() * i / 4];
            auto p = std::equal_range(arr.begin(), arr.end(), val);
            if ((p.second - p.first) * 4 > arr.size()) {
                return val;
            }
        }

        assert(false);
        return -1;
    }
};
