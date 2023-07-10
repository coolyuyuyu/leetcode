class Solution {
public:
    // Time: O(26 * 26 * N)
    int dp1(const string& s) {
        int n = s.size();

        std::function<int(const vector<int>&)> maxSubarraySumAtleastOneMinusOne = [&](const vector<int>& nums) {
            vector<int> dpEnd(n); // dpEnd[i]: the maximum subarray sum ending at i
            dpEnd[0] = nums[0];
            for (int i = 1; i < n; ++i) {
                dpEnd[i] = std::max(dpEnd[i - 1] + nums[i], nums[i]);
            }

            vector<int> dpBgn(n); // dpBgn[i]: the maximum subarray sum beginning at i
            dpBgn[n - 1] = nums[n - 1];
            for (int i = n - 1; 0 < i--;) {
                dpBgn[i] = std::max(dpBgn[i + 1] + nums[i], nums[i]);
            }

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == -1) {
                    ret = std::max(ret, dpEnd[i] + dpBgn[i] - nums[i]);
                }
            }

            return ret;
        };

        int ret = 0;

        unordered_set<char> chars(s.begin(), s.end());
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) {
                    continue;
                }

                vector<int> nums(n);
                for (int i = 0; i < n; ++i) {
                    if (s[i] == a) {
                        nums[i] = 1;
                    }
                    else if (s[i] == b) {
                        nums[i] = -1;
                    }
                    else {
                        nums[i] = 0;
                    }
                }

                ret = std::max(ret, maxSubarraySumAtleastOneMinusOne(nums));
            }
        }

        return ret;
    }

    // Time: O(26 * 26 * N)
    int dp2(const string& s) {
        int n = s.size();

        std::function<int(char, char)> f = [&](char a, char b) {
            int dp0 = 0; // dp0[i]: the maximal subarray sum ending at i, and this subarray dose NOT contain -1
            int dp1 = INT_MIN / 2; // dp1[i]: the maximal subarray sum ending at i, and this subarray dose contain -1

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                int tmp0(dp0), tmp1(dp1);
                if (s[i] == a) { // 1
                    dp0 = tmp0 + 1;
                    dp1 = tmp1 + 1;
                }
                else if (s[i] == b) { // -1
                    dp0 = 0;
                    dp1 = std::max(tmp0 - 1, tmp1 - 1);
                }

                ret = std::max(ret, dp1);
            }

            return ret;
        };

        int ret = 0;

        unordered_set<char> chars(s.begin(), s.end());
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) {
                    continue;
                }

                ret = std::max(ret, f(a, b));
            }
        }

        return ret;
    }

    // Time: O(26 * N)
    int dp3(const string& s) {
        int n = s.size();

        unordered_map<char, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[s[i]].push_back(i);
        }

        std::function<int(const vector<int>&, const vector<int>&)> f = [&](const vector<int>& indexes1, const vector<int>& indexes2) {
            int dp0 = 0; // dp0[i]: the maximal subarray sum ending at i, and this subarray dose NOT contain -1
            int dp1 = INT_MIN / 2; // dp1[i]: the maximal subarray sum ending at i, and this subarray dose contain -1

            int ret = 0;
            for (int i = 0, j = 0; i < indexes1.size() || j < indexes2.size();) {
                int tmp0(dp0), tmp1(dp1);
                if (indexes2.size() <= j || (i < indexes1.size() && indexes1[i] < indexes2[j])) { // 1
                    dp0 = tmp0 + 1;
                    dp1 = tmp1 + 1;
                    ++i;
                }
                else if (indexes1.size() <= i || (j < indexes2.size() && indexes2[j] < indexes1[i])) { // -1
                    dp0 = 0;
                    dp1 = std::max(tmp0 - 1, tmp1 - 1);
                    ++j;
                }

                ret = std::max(ret, dp1);
            }

            return ret;
        };

        int ret = 0;

        unordered_set<char> chars(s.begin(), s.end());
        for (const auto& [a, indexes1] : m) {
            for (const auto& [b, indexes2] : m) {
                if (a == b) {
                    continue;
                }

                ret = std::max(ret, f(indexes1, indexes2));
            }
        }

        return ret;
    }

    int largestVariance(string s) {
        //return dp1(s);
        //return dp2(s);
        return dp3(s);
    }
};
