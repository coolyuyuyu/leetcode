class Solution {
public:
    // Time: O(2^n)
    int dfs(const vector<int>& nums, int index, int k, vector<int>& cnts) {
        if (index == nums.size()) {
            return 1;
        }
        int num = nums[index];

        int takeN = dfs(nums, index + 1, k, cnts);
        if ((k <= num && cnts[num - k]) || (num + k < cnts.size() && cnts[num + k])) {
            return takeN;
        }

        ++cnts[num];
        int takeY = dfs(nums, index + 1, k, cnts);
        --cnts[num];
        return takeN + takeY;
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
            for (int i = 0; i < arr.size(); ++i) {\
                int tmpTakeN = takeN, tmpTakeY = takeY;
                if (0 < i && (arr[i].first - arr[i - 1].first) == k) {
                    takeN = tmpTakeN + tmpTakeY;
                    takeY = tmpTakeN * (pow(2, arr[i].second) -1);
                }
                else {
                    takeN = tmpTakeN + tmpTakeY;
                    takeY = (tmpTakeN + tmpTakeY) * (pow(2, arr[i].second) -1);
                }
            }
            ret *= (takeN + takeY);
        }

        return ret - 1;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        //vector<int> cnts(1001, 0);
        //return dfs(nums, 0, k, cnts) - 1;

        return groupAndCount(nums, k);
    }
};
