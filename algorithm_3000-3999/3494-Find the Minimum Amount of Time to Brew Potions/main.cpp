class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();

        vector<long long> endBy(n, 0);
        for (int j = 0; j < m; ++j) {
            long long maxDiff = 0, t = 0;
            for (int i = 0; i < n; ++i) {
                maxDiff = std::max(maxDiff, endBy[i] - t);
                t += 1LL * skill[i] * mana[j];
                endBy[i] = t;
            }

            for (int i = 0; i < n; ++i) {
                endBy[i] += maxDiff;
            }
        }

        return endBy[n - 1];
    }
};
