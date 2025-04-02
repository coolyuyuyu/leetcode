class Solution {
public:
    using LL = long long;

    LL M = 1e9 + 7;

    vector<int> eratosthenes(int n) {
        vector<int> scores(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            if (0 < scores[i]) {
                continue;
            }

            scores[i] = 1;
            for (int j = i * 2; j <= n; j += i) {
                ++scores[j];
            }
        }

        return scores;
    }

    LL quickPow(LL base, LL exp) {
        if (exp == 0) {
            return 1;
        }

        LL ret = quickPow(base, exp / 2);
        ret = (ret * ret) % M;
        if (exp & 1) {
            ret = (ret * base) % M;
        }

        return ret;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> scoreTbl = eratosthenes(*std::max_element(nums.begin(), nums.end()));

        int scores[n];
        for (int i = 0; i < n; ++i) {
            scores[i] = scoreTbl[nums[i]];
        }

        stack<int> stk;

        int preGE[n];
        std::fill(preGE, preGE + n, -1);
        while (!stk.empty()) { stk.pop(); }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && scores[stk.top()] < scores[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                preGE[i] = stk.top();
            }
            stk.push(i);
        }

        int nxtGT[n];
        std::fill(nxtGT, nxtGT + n, n);
        while (!stk.empty()) { stk.pop(); }
        for (int i = n; 0 < i--;) {
            while (!stk.empty() && scores[i] >= scores[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                nxtGT[i] = stk.top();
            }
            stk.push(i);
        }

        LL cnts[n];
        for (int i = 0; i < n; ++i) {
            cnts[i] = 1LL * (i - preGE[i]) * (nxtGT[i] - i);
        }

        priority_queue<pair<int, LL>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], cnts[i]);
        }

        LL ret = 1;
        while (k > 0 && !pq.empty()) {
            auto [num, cnt] = pq.top();
            pq.pop();

            long long consume = std::min<LL>(k, cnt);
            k -= cnt;

            ret *= quickPow(num, consume);
            ret %= M;
        }

        return ret;
    }
};
