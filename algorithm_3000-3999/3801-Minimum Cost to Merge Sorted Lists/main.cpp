class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();

        vector<int> state2list[1 << n];
        for (int i = 0; i < n; ++i) {
            state2list[1 << i] = lists[i];
        }
        for (int s = 1; s < (1 << n); ++s) {
            if ((s & (s - 1)) == 0) { continue; } // exclude single 1-bit
            int s1 = s & (s - 1);
            int s2 = s - s1;
            const auto& l1 = state2list[s1];
            const auto& l2 = state2list[s2];
            std::merge(l1.begin(), l1.end(), l2.begin(), l2.end(), std::back_inserter(state2list[s]));
        }

        long long state2cost[1 << n];
        for (int i = 0; i < n; ++i) {
            state2cost[1 << i] = 0;
        }

        for (int s = 0; s < (1 << n); ++s) {
            if ((s & (s - 1)) == 0) { continue; } // exclude single 1-bit
            state2cost[s] = LLONG_MAX;

            // iterate all subset, exclude 0
            for (int subset1 = s; subset1 > 0; subset1 = (subset1 - 1) & s) {
                if (subset1 * 2 > s) { continue; } // exclude duplicate split
                int subset2 = s - subset1;

                const auto& l1 = state2list[subset1];
                const auto& l2 = state2list[subset2];
                int median1 = l1[(l1.size() - 1) / 2];
                int median2 = l2[(l2.size() - 1) / 2];
                state2cost[s] = std::min<long long>(state2cost[s], state2cost[subset1] + state2cost[subset2] + l1.size() + l2.size() + std::abs(median1 - median2));
            }
        }

        return state2cost[(1 << n) - 1];
    }
};
