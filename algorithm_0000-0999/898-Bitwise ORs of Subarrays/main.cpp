class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // dp[i]: or sum from all subarrays ending at arr[i]
        unordered_set<int> dp;

        unordered_set<int> ret;
        for (int x : arr) {
            unordered_set<int> tmp = std::move(dp);
            for (int y : tmp) {
                dp.insert(x | y);
            }
            dp.insert(x);

            ret.insert(dp.begin(), dp.end());
        }

        return ret.size();
    }
};
