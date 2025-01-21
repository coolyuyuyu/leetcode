LeetCode Logo
Problem List
793

avatar
Debugging...
Debugging...







Run
Description
Description
Accepted
Editorial
Editorial
Solutions
Solutions
Submissions
Submissions
Debugger
Debugger
Code


Testcase
Testcase
Test Result
C++

Auto





128129130131132133134
        return byDP3(nums);
    }
};

Saved
Accepted
Runtime: 0 ms
Case 1
Case 2
Case 3
Case 4
Case 5
Input
nums =
[5,3,11,19,2]
Output
true
Expected
true
Contribute a testcase
All Submissions

Accepted
111 / 111 testcases passed
Chuck
submitted at Jan 21, 2025 23:55


Solution
Runtime
391
ms
Beats
35.82%
Analyze Complexity
Memory
16.10
MB
Beats
88.43%
Analyze Complexity
Code
C++
class Solution {
public:
    // DFS, TLE
    bool byDFS(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        std::function<bool(int, int, int)> f = [&](int i, int cnt, int sum) {
            if (cnt == 0 && sum == 0) { return true; }
            if (i >= n || cnt == 0 || sum == 0) { return false; }

            if (f(i + 1, cnt - 1, sum - nums[i])) { return true; }

            int j = i + 1;
            while (j < n && nums[i] == nums[j]) {
                ++j;
            }
            if (f(j, cnt, sum)) { return true; }

            return false;
        };

        for (int cnt = 1; cnt <= n / 2; ++cnt) {
            if (sum * cnt % n != 0) { continue; }
            if (f(0, cnt, sum * cnt / n)) {
                return true;
            }
        }

        return false;
    }

    // state compression DP, TLE
    bool byDP1(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        for (int cnt = 1; cnt <= n / 2; ++cnt) {
            if (sum * cnt % n != 0) { continue; }

            // Gosper's hack: Iterate all the n-bit state where there are cnt 1-bits.
            int state = (1 << cnt) - 1;
            while (state < (1 << n)) {
                int subsum = 0;
                for (int i = 0; i < n; ++i) {
                    if ((state >> i) & 1) {
                        subsum += nums[i];
                    }
                }
                if (subsum == sum * cnt / n) {
                    return true;
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return false;
    }

    bool byDP2(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        nums.insert(nums.begin(), -1);

        bool dp[sum + 1][n + 1];
        for (int s = 0; s <= sum / 2; ++s) {
            for (int cnt = 0; cnt <= n; ++cnt) {
                dp[s][cnt] = false;
            }
        }
        dp[0][0] = true;

        bool tmp[sum + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            std::memcpy(tmp, dp, sizeof(dp));
            for (int s = 0; s <= sum / 2; ++s) {
                for (int cnt = 1; cnt <= i; ++cnt) {
                    if (s < nums[i]) { continue; }
                    if (tmp[s - nums[i]][cnt - 1]) {
                        dp[s][cnt] = true;
                        if (cnt != n && (s * n == sum * cnt)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool byDP3(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        nums.insert(nums.begin(), -1);

        bool dp[sum + 1][n + 1];
        for (int s = 0; s <= sum; ++s) {
            for (int cnt = 0; cnt <= n; ++cnt) {
                dp[s][cnt] = false;
            }
        }
        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int s = sum / 2; s >= 0; --s) {
                for (int cnt = i; cnt >= 1; --cnt) {
                    if (s < nums[i]) { continue; }
                    if (dp[s - nums[i]][cnt - 1]) {
                        dp[s][cnt] = true;
                        if (cnt != n && (s * n == sum * cnt)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        //return byDFS(nums);
        //return byDP1(nums);
        //return byDP2(nums);
        return byDP3(nums);
    }
};
