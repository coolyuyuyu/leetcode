class Solution {
public:
    // Time: O(26 * 26 * n)
    int dp_sol1(const string& s) {
        int n = s.size();

        std::function<int(const vector<int>&)> maxSubArrAtleastOneMinus = [n](const vector<int>& nums) {
            // Kadane

            // dp0[i]: maximum subarray sum ending at i
            vector<int> dp0(n);
            dp0[0] = nums[0];
            for (int i = 1; i < n; ++i) {
                dp0[i] = std::max(dp0[i - 1] + nums[i], nums[i]);
            }

            // dp1[i]: maximum subarray sum starting at i
            vector<int> dp1(n);
            dp1[n - 1] = nums[n - 1];
            for (int i = n - 1; 0 < i--;) {
                dp1[i] = std::max(dp1[i + 1] + nums[i], nums[i]);
            }

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == -1) {
                    ret = std::max(ret, dp0[i] + dp1[i] - nums[i]);
                }
            }

            return ret;
        };

        int ret = 0;
        set<char> chars(s.begin(), s.end());
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) {
                    continue;
                }

                vector<int> nums(n);
                for (int k = 0; k < n; ++k) {
                    if (s[k] == a) {
                        nums[k] = 1;
                    }
                    else if (s[k] == b) {
                        nums[k] = -1;
                    }
                    else {
                        nums[k] = 0;
                    }
                }

                ret = std::max(ret, maxSubArrAtleastOneMinus(nums));
            }
        }

        return ret;
    }

    // Time: O(26 * 26 * n)
    int dp_sol2_1(const string& s) {
        int n = s.size();

        std::function<int(const vector<int>&)> maxSubArrAtleastOneMinus = [n](const vector<int>& nums) {
            // Kadane

            // dp0[i]: maximum subarray sum ending at i, and this subarray does not contain -1
            // dp1[i]: maximum subarray sum ending at i, and this subarray does contain -1
            vector<int> dp0(n), dp1(n);
            dp0[0] = (nums[0] == -1 ? 0 : nums[0]);
            dp1[0] = (nums[0] == -1 ? nums[0] : INT_MIN / 2);
            for (int i = 1; i < n; ++i) {
                if (nums[i] == 1) {
                    dp0[i] = dp0[i - 1] + 1;
                    dp1[i] = dp1[i - 1] + 1;
                }
                else if (nums[i] == 0) {
                    dp0[i] = dp0[i - 1];
                    dp1[i] = dp1[i - 1];
                }
                else if (nums[i] == -1) {
                    dp0[i] = 0;
                    dp1[i] = std::max(dp0[i - 1] - 1, dp1[i - 1] - 1);
                }
            }

            return *std::max_element(dp1.begin(), dp1.end());
        };

        int ret = 0;
        set<char> chars(s.begin(), s.end());
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) {
                    continue;
                }

                vector<int> nums(n);
                for (int k = 0; k < n; ++k) {
                    if (s[k] == a) {
                        nums[k] = 1;
                    }
                    else if (s[k] == b) {
                        nums[k] = -1;
                    }
                    else {
                        nums[k] = 0;
                    }
                }

                ret = std::max(ret, maxSubArrAtleastOneMinus(nums));
            }
        }

        return ret;
    }

    // Time: O(26 * 26 * n)
    int dp_sol2_2(const string& s) {
        int n = s.size();

        std::function<int(const vector<int>&)> maxSubArrAtleastOneMinus = [n](const vector<int>& nums) {
            // Kadane

            // dp0[i]: maximum subarray sum ending at i, and this subarray does not contain -1
            // dp1[i]: maximum subarray sum ending at i, and this subarray does contain -1
            int dp0 = 0, dp1 = INT_MIN / 2;
            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 1) {
                    dp0 = dp0 + 1;
                    dp1 = dp1 + 1;
                }
                else if (nums[i] == -1) {
                    dp1 = std::max(dp0 - 1, dp1 - 1);
                    dp0 = 0;
                }

                ret = std::max(ret, dp1);
            }

            return ret;
        };

        int ret = 0;
        set<char> chars(s.begin(), s.end());
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) {
                    continue;
                }

                vector<int> nums(n);
                for (int k = 0; k < n; ++k) {
                    if (s[k] == a) {
                        nums[k] = 1;
                    }
                    else if (s[k] == b) {
                        nums[k] = -1;
                    }
                    else {
                        nums[k] = 0;
                    }
                }

                ret = std::max(ret, maxSubArrAtleastOneMinus(nums));
            }
        }

        return ret;
    }

    // Time: O(26 * 26 * n)
    int dp_sol2_3(const string& s) {
        int n = s.size();

        int ret = 0;
        set<char> chars(s.begin(), s.end());
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) {
                    continue;
                }

                int dp0 = 0, dp1 = INT_MIN / 2;
                for (int k = 0; k < n; ++k) {
                    if (s[k] == a) {
                        dp0 = dp0 + 1;
                        dp1 = dp1 + 1;
                    }
                    else if (s[k] == b) {
                        dp1 = std::max(dp0 - 1, dp1 - 1);
                        dp0 = 0;
                    }

                    ret = std::max(ret, dp1);
                }
            }
        }

        return ret;
    }

    // Time: O(26 * n)
    int dp_sol2_4(const string& s) {
        int n = s.size();

        map<char, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[s[i]].push_back(i);
        }

        int ret = 0;
        for (const auto& [a, pos1] : m) {
            for (const auto& [b, pos2] : m) {
                if (a == b) {
                    continue;
                }

                int dp0 = 0, dp1 = INT_MIN / 2;
                for (int i = 0, j = 0; i < pos1.size() || j < pos2.size();) {
                    if (j == pos2.size() || (i < pos1.size() && pos1[i] < pos2[j])) {
                        dp0 = dp0 + 1;
                        dp1 = dp1 + 1;
                        ++i;
                    }
                    else {
                        dp1 = std::max(dp0 - 1, dp1 - 1);
                        dp0 = 0;
                        ++j;
                    }

                    ret = std::max(ret, dp1);
                }
            }
        }

        return ret;
    }

    int largestVariance(string s) {
        //return dp_sol1(s);
        //return dp_sol2_1(s);
        //return dp_sol2_2(s);
        //return dp_sol2_3(s);
        return dp_sol2_4(s);
    }
};
