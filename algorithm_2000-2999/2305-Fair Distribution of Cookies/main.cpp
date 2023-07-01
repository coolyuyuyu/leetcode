class Solution {
public:
    int dfs(const vector<int>& cookies, int k) {
        vector<int> plans(k, 0);

        int ret = INT_MAX;
        std::function<void(int)> f = [&](int cookieIdx) {
            if (cookies.size() <= cookieIdx) {
                ret = std::min(ret, *std::max_element(plans.begin(), plans.end()));
                return;
            }

            for (int i = 0; i < k; ++i) {
                plans[i] += cookies[cookieIdx];
                f(cookieIdx + 1);
                plans[i] -= cookies[cookieIdx];
            }
        };
        f(0);

        return ret;
    }

    int bsearch_dfs_cookies(vector<int>& cookies, int k) {
        vector<int> plans(k);
        std::function<bool(int, int)> unfairLE = [&](int cookieIdx, int limit) {
            if (cookies.size() <= cookieIdx) {
                return true;
            }

            for (int i = 0; i < k; ++i) {
                if (limit < (plans[i] + cookies[cookieIdx])) {
                    continue;
                }

                plans[i] += cookies[cookieIdx];
                if (unfairLE(cookieIdx + 1, limit)) {
                    return true;
                }
                plans[i] -= cookies[cookieIdx];
            }

            return false;
        };

        std::sort(cookies.rbegin(), cookies.rend());
        int lo = cookies[0], hi = std::accumulate(cookies.begin(), cookies.end(), 0);
        while (lo < hi) {
            for (int& plan : plans) {
                plan = 0;
            }

            int mid = lo + (hi - lo) / 2;
            if (unfairLE(0, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int bsearch_dfs_people(vector<int>& cookies, int k) {
        vector<int> plans(k);
        std::function<bool(int, int, int)> unfairLE = [&](int peopleIdx, int state, int limit) {
            if (plans.size() <= peopleIdx) {
                return state == 0;
            }

            for (int subset = state; 0 < subset; subset = (subset - 1) & state) {
                int sum = 0;
                for (int i = 0; i < cookies.size(); ++i) {
                    if ((subset >> i) & 1) {
                        sum += cookies[i];
                    }
                }
                if (limit < sum) {
                    continue;
                }

                if (unfairLE(peopleIdx + 1, state - subset, limit)) {
                    return true;
                }
            }

            return false;
        };

        std::sort(cookies.rbegin(), cookies.rend());
        int lo = cookies[0], hi = std::accumulate(cookies.begin(), cookies.end(), 0);
        while (lo < hi) {
            for (int& plan : plans) {
                plan = 0;
            }

            int mid = lo + (hi - lo) / 2;
            if (unfairLE(0, (1 << cookies.size()) - 1, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        //return dfs(cookies, k);
        return bsearch_dfs_cookies(cookies, k);
        //return bsearch_dfs_people(cookies, k);
    }
};
