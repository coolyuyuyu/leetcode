class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        std::sort(price.begin(), price.end());

        auto isOk = [&price, k](int minDiff) -> bool {
            for (int cnt = 1, pre = 0, i = 1; i < price.size(); ++i) {
                if (minDiff <= (price[i] - price[pre])) {
                    pre = i;
                    if (k <= ++cnt) {
                        return true;
                    }
                }
            }
            return false;
        };

        int lft = 0, rht = 1e9;
        while (lft < rht) {
            int mid = rht - (rht - lft) / 2;
            if (isOk(mid)) {
                lft = mid;
            }
            else {
                rht = mid - 1;
            }
        }

        return lft;
    }
};
