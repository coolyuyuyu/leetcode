class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        size_t n = nums1.size();

        unordered_set<int> s1, s2, s;
        for (int num : nums1) {
            s1.insert(num);
            s.insert(num);
        }
        for (int num : nums2) {
            s2.insert(num);
            s.insert(num);
        }

        return std::min(std::min(n / 2, s1.size()) + std::min(n / 2, s2.size()), s.size());
    }
};
