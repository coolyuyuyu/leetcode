class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> factor2cnt;
        for (int num : nums1) {
            for (int a = 1, n = sqrt(num); a <= n; ++a) {
                if (num % a != 0) { continue; }
                ++factor2cnt[a];
                int b = num / a;
                if (b != a) {
                    ++factor2cnt[b];
                }
            }
        }

        long long ret = 0;
        for (int num : nums2) {
            num *= k;
            if (factor2cnt.find(num) != factor2cnt.end()) {
                ret += factor2cnt[num];
            }
        }

        return ret;
    }
};
