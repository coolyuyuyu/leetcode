class Solution {
public:
    // Time: O(n^2)
    int f1(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int ret = 0;
        for (int shift = 0; shift < n; ++shift) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums1[(shift + i) % n] == nums2[i]) {
                    ++cnt;
                }
            }
            ret = std::max(ret, cnt);
        }

        return ret;
    }

    // Time: Worst O(n^2), Best O(n)
    int f2(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int, vector<int>> num2indexes;
        for (int i = 0; i < n; ++i) {
            num2indexes[nums1[i]].push_back(i);
        }

        vector<int> scores(n, 0);
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i : num2indexes[nums2[j]]) {
                int shift = (j - i + n) % n;
                ++scores[shift];
            }
        }

        return *std::max_element(scores.begin(), scores.end());
    }

    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        //return f1(nums1, nums2);
        return f2(nums1, nums2);
    }
};
