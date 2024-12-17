class Solution {
public:
    int M = 1e9 + 7;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        int n = nums.size();

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }

        unordered_set<int> indexes;
        for (; k > 0 && indexes.size() < n; --k) {
            auto [num, i] = pq.top();
            pq.pop();

            indexes.insert(i);

            num *= multiplier;
            pq.emplace(num, i);
        }

        std::function<int(int, int)> quickPow = [&](int base, int exp) {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = (1L * ret * base) % M;
                }
                base = (1L * base * base) % M;
            }
            return ret;
        };
        int quotient = k / n, reminder = k % n;
        int m1 = quickPow(multiplier, quotient);
        int m2 = quickPow(multiplier, quotient + 1);

        for (; !pq.empty(); --reminder) {
            auto [num, i] = pq.top();
            pq.pop();
            nums[i] = num % M * (reminder > 0 ? m2 : m1) % M;
        }

        return nums;
    }
};
