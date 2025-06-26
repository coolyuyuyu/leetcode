class Solution {
public:
    // Time: O(logX * (M * logN))
    long long bsearch1(vector<int>& nums1, vector<int>& nums2, long long k) {
        std::function<long long(long long)> cntPairsLE = [&](long long target) {
            long long ret = 0;
            for (int num1 : nums1) {
                if (num1 < 0) {
                    // nums2[j] >= target / nums1
                    auto itr = std::lower_bound(nums2.begin(), nums2.end(), std::ceil(1.0 * target / num1));
                    ret += std::distance(itr, nums2.end());
                }
                else if (num1 == 0) {
                    if (target >= 0) {
                        ret += nums2.size();
                    }
                }
                else {
                    // nums2[j] <= target / nums1
                    auto itr = std::upper_bound(nums2.begin(), nums2.end(), std::floor(1.0 * target / num1));
                    ret += std::distance(nums2.begin(), itr);
                }
            }

            return ret;
        };

        long long lo = -1e10, hi = 1e10;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cntPairsLE(mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    // Time: O(logX * (M + N))
    long long bsearch2(vector<int>& nums1, vector<int>& nums2, long long k) {
        int m = nums1.size(), n = nums2.size();

        std::function<long long(long long)> cntPairsLE = [&](long long target) {
            long long ret = 0;
            if (target >= 0) {
                int j0 = n - 1, j1 = n - 1;
                for (int i = 0; i < nums1.size(); ++i) {
                    if (nums1[i] < 0) {
                        // nums2[j] > target / nums1[i]
                        while (j0 >= 0 && 1LL * nums1[i] * nums2[j0] <= target) {
                            --j0;
                        }
                        ret += (n - 1) - (j0 + 1) + 1;
                    }
                    else if (nums1[i] == 0) {
                        ret += n;
                    }
                    else {
                        // nums2[j] <= target / nums1[i]
                        while (j1 >= 0 && 1LL * nums1[i] * nums2[j1] > target) {
                            --j1;
                        }
                        ret += (j1) - (0) + 1;
                    }
                }
            }
            else
            {
                int j0 = 0, j1 = 0;
                for (int i = 0; i < nums1.size(); ++i) {
                    if (nums1[i] < 0) {
                        // nums2[j] > target / nums1[i]
                        while (j0 < n && 1LL * nums1[i] * nums2[j0] > target) {
                            ++j0;
                        }
                        ret += (n - 1) - (j0) + 1;
                    }
                    else if (nums1[i] == 0) {
                        ret += 0;
                    }
                    else {
                        // nums2[j] <= target / nums1[i]
                        while (j1 < n && 1LL * nums1[i] * nums2[j1] <= target) {
                            ++j1;
                        }
                        ret += (j1 - 1) - (0) + 1;
                    }
                }
            }

            return ret;
        };

        long long lo = -1e10, hi = 1e10;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cntPairsLE(mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        //return bsearch1(nums1, nums2, k);
        return bsearch2(nums1, nums2, k);
    }
};
