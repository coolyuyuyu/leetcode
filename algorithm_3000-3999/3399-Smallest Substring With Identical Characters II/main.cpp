class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.size();

        vector<int> lens;
        for (int lft = 0, rht = 1; lft < n; lft = rht, rht = lft + 1) {
            while (rht < n && s[lft] == s[rht]) {
                ++rht;
            };
            lens.push_back(rht - lft);
        }

        std::function<bool(int)> checkOk = [&](int k) {
            if (k == 1) {
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    cnt += (s[i] - '0') == (i & 1);
                }
                return std::min(cnt, n - cnt) <= numOps;
            }
            else {
                int cnt = 0;
                for (int len : lens) {
                    cnt += std::ceil(1.0 * (len - k) / (k + 1));
                    if (cnt > numOps) {
                        return false;
                    }
                }
                return true;
            }
        };

        int lo = 1, hi = s.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
