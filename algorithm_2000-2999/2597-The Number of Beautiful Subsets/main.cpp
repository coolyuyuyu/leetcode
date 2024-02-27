class Solution {
public:
    // Time: O(2^n)
    int dfs(vector<int>& nums, int k) {
        int n = nums.size();

        int cnts[1001];
        std::fill(cnts, cnts + 1001, 0);
        std::function<int(int)> f = [&](int cur) {
            if (cur >= n) {
                return 1;
            }

            int num = nums[cur];
            int takeN = f(cur + 1);
            if ((num - k >= 0 && cnts[nums[cur] - k]) || (num + k <= 1000 && cnts[num + k])) {
                return takeN;
            }
            else {
                ++cnts[num];
                int takeY = f(cur + 1);
                --cnts[num];
                return takeN + takeY;
            }
        };

        return f(0) - 1;
    }

    // Time: O(nlogn)
    int dp(vector<int>& nums, int k) {
        unordered_map<int, vector<pair<int, int>>> reminder2numcnts; {
            unordered_map<int, int> num2cnt;
            for (int num : nums) {
                ++num2cnt[num];
            }
            for (const auto& [num, cnt] : num2cnt) {
                reminder2numcnts[num % k].emplace_back(num, cnt);
            }
        }

        int ret = 1;
        for (auto& [_, numcnts] : reminder2numcnts) {
            std::sort(numcnts.begin(), numcnts.end(), [](auto& nc1, auto& nc2){ return nc1.first < nc2.first; });

            // house robber
            // takeN[i]: the number of combinations from numcnts[0:i], and numcnts[i] is included in the combinations
            // takeY[i]: the number of combinations from numcnts[0:i], and numcnts[i] is NOT included in the combinations
            int takeN = 1, takeY = 0;
            for (int i = 0; i < numcnts.size(); ++i) {
                int tmpN = takeN, tmpY = takeY;
                if (i > 0 && numcnts[i].first - numcnts[i - 1].first == k) {
                    takeN = tmpN + tmpY;
                    takeY = tmpN * ((1 << numcnts[i].second) - 1);
                }
                else {
                    takeN = tmpN + tmpY;
                    takeY = (tmpN + tmpY) * ((1 << numcnts[i].second) - 1);
                }
            }

            ret *= (takeN + takeY);
        }

        return ret - 1;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        //return dfs(nums, k);
        return dp(nums, k);
    }
};
