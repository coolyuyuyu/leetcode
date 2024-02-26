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
    int groupAndCount(const vector<int>& nums, int k) {
        unordered_map<int, vector<pair<int, int>>> reminder2numcnt; { // reminder -> vector<pair<num, cnt>>
            unordered_map<int, int> num2cnt;
            for (int num : nums) {
                ++num2cnt[num];
            }

            for (const auto [num, cnt] : num2cnt) {
                reminder2numcnt[num % k].emplace_back(num, cnt);
            }
        }

        int ret = 1;
        for (auto& [_, arr] : reminder2numcnt) {
            std::sort(
                arr.begin(), arr.end(),
                [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.first < p2.first; });

            int takeN = 1, takeY = 0;
            for (int i = 0; i < arr.size(); ++i) {
                int tmpTakeN = takeN, tmpTakeY = takeY;
                if (0 < i && (arr[i].first - arr[i - 1].first) == k) {
                    takeN = tmpTakeN + tmpTakeY;
                    takeY = tmpTakeN * (pow(2, arr[i].second) - 1);
                }
                else {
                    takeN = tmpTakeN + tmpTakeY;
                    takeY = (tmpTakeN + tmpTakeY) * (pow(2, arr[i].second) - 1);
                }
            }
            ret *= (takeN + takeY);
        }

        return ret - 1;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        return dfs(nums, k);
        //return groupAndCount(nums, k);
    }
};
