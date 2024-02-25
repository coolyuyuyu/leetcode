class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        int n = y.size();

        map<double, int> diffs;
        for (int i = 1; i < n; ++i) {
            int a = y[i - 1], b = y[i];
            if (a < b) { // [a, b)
                diffs[a] += 1;
                diffs[b] -= 1;
            }
            else { // [b, a)
                diffs[b + 0.1] += 1;
                diffs[a + 0.1] -= 1;
            }
        }
        diffs[y[n - 1]] += 1;
        diffs[y[n - 1] + 0.1] -= 1;

        int ret = 0;
        int sum = 0;
        for (const auto& [_, diff] : diffs) {
            sum += diff;
            ret = std::max(ret, sum);
        }

        return ret;
    }
};
