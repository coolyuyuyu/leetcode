class Solution {
public:
    long long countLE(vector<int>& coins, long long target) {
        int n = coins.size();

        long long ret = 0;
        for (int s = 1; s < (1 << n); ++s) {
            int popcnt = 0;
            long long lcm = 1;
            for (int i = 0; i < n; ++i) {
                if ((s >> i) & 1) {
                    ++popcnt;
                    lcm = std::lcm(lcm, coins[i]);
                }
            }

            ret += target / lcm * (popcnt & 1 ? 1 : -1);
        }

        return ret;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        // optimization: remove multiples
        std::sort(coins.begin(), coins.end());
        vector<int> tmp = std::move(coins);
        for (int num : tmp) {
            bool divisible = false;
            for (int coin : coins) {
                if (num % coin == 0) {
                    divisible = true;
                    break;
                }
            }
            if (!divisible) {
                coins.push_back(num);
            }
        }

        long long lo = 0, hi = LLONG_MAX;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(coins, mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
