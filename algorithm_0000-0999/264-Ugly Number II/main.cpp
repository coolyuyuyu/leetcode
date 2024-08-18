class Solution {
public:
    // Time: O(NlogN)
    int byHeap(int n) {
        priority_queue<long long, vector<long long>, std::greater<long long>> pq;
        long long num = 1;
        for (int i = 1; i < n; ++i) {
            pq.push(num * 2);
            pq.push(num * 3);
            pq.push(num * 5);

            num = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() <= num) {
                pq.pop();
            }
        }

        return num;
    }

    // Time: O(N)
    int byDP(int n) {
        int dp[n];
        dp[0] = 1;
        for (int x = 1, i = 0, j = 0, k = 0; x < n; ++x) {
            int num = std::min({dp[i] * 2, dp[j] * 3, dp[k] * 5});
            if (num == dp[i] * 2) { ++i; }
            if (num == dp[j] * 3) { ++j; }
            if (num == dp[k] * 5) { ++k; }
            dp[x] = num;
        }

        return dp[n - 1];
    }

    int nthUglyNumber(int n) {
        //return byHeap(n);
        return byDP(n);
    }
};
