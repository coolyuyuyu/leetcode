class Solution {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i != 0) { continue; }
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
        std::sort(divisors.begin(), divisors.end());

        vector<int> cur, ret;
        int minDiff = INT_MAX;
        std::function<void(int num, int i)> f = [&](int num, int i) {
            if (cur.size() + 1 == k) {
                cur.push_back(num);
                int curDiff = cur.back() - cur.front();
                if (curDiff < minDiff) {
                    minDiff = curDiff;
                    ret = cur;
                }
                cur.pop_back();
                return;
            }

            for (; i < divisors.size(); ++i) {
                if (divisors[i] > num) { break; }
                if (num / divisors[i] < divisors[i]) { break; }
                if (num % divisors[i] != 0) { continue; }
                cur.push_back(divisors[i]);
                f(num / divisors[i], i);
                cur.pop_back();
            }
        };
        f(n, 0);

        return ret;
    }
};
