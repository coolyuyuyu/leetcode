class Solution {
public:
    int topdn_helper(const string& sentence, int k, size_t start) {
        if (sentence.size() <= (start + k)) {
            return 0;
        }

        int minCost = INT_MAX;
        for (size_t i = start + 1; i <= start + k; ++i) {
            if (sentence[i] == ' ') {
                int cost = (k - (i - start)) * (k - (i - start));
                minCost = std::min(minCost, topdn_helper(sentence, k, i + 1) + cost);
            }
        }

        return minCost;
    }

    // TLE
    int topdn(const string& sentence, int k) {
        return topdn_helper(sentence, k , 0);
    }

    int topdn_memo_helper(const string& sentence, int k, size_t start, vector<int>& cache) {
        if ((start + k) >= sentence.size()) {
            return 0;
        }
        if (0 <= cache[start]) {
            return cache[start];
        }

        int minCost = INT_MAX;
        for (size_t i = start + 1; i <= start + k; ++i) {
            if (sentence[i] == ' ') {
                int cost = (k - (i - start)) * (k - (i - start));
                minCost = std::min(minCost, topdn_memo_helper(sentence, k, i + 1, cache) + cost);
            }
        }
        cache[start] = minCost;

        return cache[start];
    }

    int topdn_memo(const string& sentence, int k) {
        vector<int> cache(sentence.size(), -1);
        return topdn_memo_helper(sentence, k, 0, cache);
    }

    int btmup1(const string& sentence, int k) {
        vector<int> lens; {
            for (size_t pre = 0, cur = 0; cur <= sentence.size(); ++cur) {
                if (cur == sentence.size() || sentence[cur] == ' ') {
                    lens.push_back(cur - pre);
                    pre = cur + 1;
                }
            }
        }

        // n strings
        // size of dp: n + 1
        // dp[n]: minCost from 0th - (n-1)th strs
        // dp[1]: minCost from 0th - (0)th strs
        // dp[0]: 0
        vector<int> dp(lens.size() + 1, INT_MAX);
        dp[0] = 0;

        int ans = 0;
        for (size_t i = 0; i < dp.size(); ++i) {
            if (i + 1 == dp.size()) {
                ans = INT_MAX;
            }

            int lastLen = 0;
            for (size_t j = i; 0 < j--; ) {
                lastLen += lens[j];
                if (j + 1 < i) {
                    lastLen += 1;
                }
                if (k < lastLen) {
                    break;
                }
                dp[i] = std::min(dp[i], dp[j] + (k - lastLen) * (k - lastLen));

                if (i + 1 == dp.size()) {
                    ans = std::min(ans, dp[j]);
                }
            }
        }


        return ans;
    }

    int btmup2(const string& sentence, int k) {
        vector<int> dp(sentence.size(), INT_MAX);
        for (size_t i = dp.size(); 0 < i; --i) {
            if (i == dp.size() || i == 0 || sentence[i - 1] == ' ') {
                size_t to;
                if (i == dp.size()) {
                    to = (i >= k ? i - k : 0);
                }
                else {
                    to = (i >= (k + 1) ? (i - k - 1) : 0);
                }

                for (size_t j = i; to < j--;) {
                    if (j == 0 || sentence[j - 1] == ' ') {
                        if (j + k >= sentence.size()) {
                            dp[j] = 0;
                        }
                        else {
                            int cost = (k - i + j + 1) * (k - i + j + 1);
                            dp[j] = min(dp[j], dp[i] + cost);
                        }
                    }
                }
            }
        }

        return dp[0];
    }

    int minimumCost(string sentence, int k) {
        //return topdn(sentence, k);
        return topdn_memo(sentence, k);

        //return btmup1(sentence, k);
        //return btmup2(sentence, k);
    }
};
