class Solution {
public:
    int byDp(const vector<int>& jobs, int k) {
        int n = jobs.size();

        // time[state]: the sum of time of jobs of state
        vector<int> time(1 << n, 0);
        for (int state = 1; state < (1 << n); ++state) {
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    time[state] += jobs[i];
                }
            }
        }

        // dp[i][state]: the minimum possible maximum working time of any assignment if we use i workers and completes jobs of state.
        vector<vector<int>> dp(k + 1, vector<int>(1 << n));
        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            dp[i][0] = 0;
        }
        for (int state = 1; state < (1 << n); ++state) {
            dp[0][state] = INT_MAX;
        }
        for (int i = 1; i <= k; ++i) {
            for (int state = 1; state < (1 << n); ++state) {
                dp[i][state] = INT_MAX;
                for (int subset = state; 0 < subset; subset = (subset - 1) & state) {
                    dp[i][state] = std::min(dp[i][state], std::max(dp[i - 1][state - subset], time[subset]));
                }
            }
        }

        return dp[k][(1 << n) - 1];
    }

    // TLE
    int byDfsJobs(vector<int>& jobs, int k) {
        vector<int> times(k, 0);

        int ret = INT_MAX;
        std::function<void(int)> f = [&](int jobIdx) {
            if (jobs.size() <= jobIdx) {
                ret = std::min(ret, *std::max_element(times.begin(), times.end()));
                return;
            }

            unordered_set<int> duplicate;
            for (int i = 0; i < k; ++i) {
                if (duplicate.insert(times[i]).second) {
                    times[i] += jobs[jobIdx];
                    f(jobIdx + 1);
                    times[i] -= jobs[jobIdx];
                }
            }
        };
        f(0);

        return ret;
    }

    // TLE
    int byDfsWorkers(vector<int>& jobs, int k) {
        int n = jobs.size();

        // time[state]: the sum of time of jobs of state
        vector<int> time(1 << n, 0);
        for (int state = 1; state < (1 << n); ++state) {
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    time[state] += jobs[i];
                }
            }
        }

        std::function<int(int, int)> f = [&](int state, int workerIdx) {
            if (k <= workerIdx) {
                return state == 0 ? 0 : INT_MAX;
            }

            int ret = INT_MAX;
            for (int subset = state; 0 < subset; subset = (subset - 1) & state) {
                ret = std::min(ret, std::max(time[subset], f(state - subset, workerIdx + 1)));
            }

            return ret;
        };
        return f((1 << n) - 1, 0);
    }

    int byBSearchDfsJobs(vector<int>& jobs, int k) {
        std::sort(jobs.rbegin(), jobs.rend());
        int lo = jobs[0], hi = std::accumulate(jobs.begin(), jobs.end(), 0);

        vector<int> times(k, 0);
        std::function<bool(int, int)> f = [&](int jobIdx, int limit) {
            if (jobs.size() <= jobIdx) {
                return true;
            }

            unordered_set<int> duplicates;
            for (int i = 0; i < k; ++i) {
                if (limit < (times[i] + jobs[jobIdx])) {
                    continue;
                }

                if (duplicates.insert(times[i]).second) {
                    times[i] += jobs[jobIdx];
                    if (f(jobIdx + 1, limit)) {
                        return true;
                    }
                    times[i] -= jobs[jobIdx];
                }
            }

            return false;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            std::fill(times.begin(), times.end(), 0);
            if (f(0, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int byBSearchDfsWorkers(vector<int>& jobs, int k) {
        int n = jobs.size();

        // time[state]: the sum of time of jobs of state
        vector<int> time(1 << n, 0);
        for (int state = 1; state < (1 << n); ++state) {
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    time[state] += jobs[i];
                }
            }
        }

        int lo = *std::max_element(jobs.begin(), jobs.end()), hi = std::accumulate(jobs.begin(), jobs.end(), 0);

        bool cache[1 << n][k];
        std::function<bool(int, int, int)> f = [&](int state, int workerIdx, int limit) {
            if (state == 0) {
                return true;
            }
            if (k <= workerIdx) {
                return false;
            }
            if (cache[state][workerIdx]) {
                return false;
            }

            for (int subset = state; 0 < subset; subset = (subset - 1) & state) {
                if (limit < time[subset]) {
                    continue;
                }

                if (f(state - subset, workerIdx + 1, limit)) {
                    return true;
                }
            }

            cache[state][workerIdx] = true;
            return false;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            for (int state = 0; state < (1 << n); ++state) {
                for (int i = 0; i < k; ++i) {
                    cache[state][i] = false;
                }
            }
            if (f((1 << n) - 1, 0, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        //return byDp(jobs, k);

        //return byDfsJobs(jobs, k);
        //return byDfsWorkers(jobs, k);

        //return byBSearchDfsJobs(jobs, k);
        return byBSearchDfsWorkers(jobs, k);
    }
};
