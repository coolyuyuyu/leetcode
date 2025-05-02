class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();

        std::sort(tasks.rbegin(), tasks.rend());
        multiset<int> mset(workers.begin(), workers.end());
        std::function<bool(int)> assignKTasks = [&](int k) {
            if (k > n) { return false; }
            if (k > m) { return false; }

            multiset<int> ms = mset;
            int p = pills;
            for (int i = n - k; i < n; ++i) {
                if (*ms.rbegin() >= tasks[i]) {
                    ms.erase(std::prev(ms.end()));
                }
                else if (p > 0) {
                    auto itr = ms.lower_bound(tasks[i] - strength );
                    if (itr == ms.end()) { return false; }
                    ms.erase(itr);
                    --p;
                }
                else {
                    return false;
                }
            }

            return true;
        };

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (assignKTasks(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
