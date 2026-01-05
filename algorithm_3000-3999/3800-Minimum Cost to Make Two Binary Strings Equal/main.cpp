class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                s[i] == '0' ? ++cnt0 : ++cnt1;
            }
        }

        long long ret1 = 1LL * (cnt0 + cnt1) * flipCost;
        long long ret2 = 1LL * std::min(cnt0, cnt1) * swapCost + 1LL * std::abs(cnt0 - cnt1) * flipCost;
        long long ret3 = 1LL * std::min(cnt0, cnt1) * swapCost + 1LL *std::abs(cnt0 - cnt1) / 2 * (crossCost + swapCost) + (std::abs(cnt0 - cnt1) & 1 ? flipCost : 0);

        return std::min({ret1, ret2, ret3});
    }
};
