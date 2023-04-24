class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> cnts(101, 0);
        for (int i = 0; (i + 1) < k; ++i) {
            ++cnts[nums[i] + 50];
        }

        auto f = [&cnts, x]() {
            int cnt = 0;
            for (int i = 0; i < 50; ++i) {
                cnt += cnts[i];
                if (x <= cnt) {
                    return i - 50;
                }
            }

            return 0;
        };

        vector<int> ret;
        for (int i = k - 1; i < nums.size(); ++i) {
            if (0 <= (i - k)) {
                --cnts[nums[i - k] + 50];
            }
            ++cnts[nums[i] + 50];

            ret.push_back(f());
        }

        return ret;
    }
};
