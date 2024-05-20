class Solution {
public:
    int dfs(vector<int>& nums) {
        std::function<int(int, int)> f = [&](int i, int sum) {
            if (i >= nums.size()) {
                return sum;
            }

            return f(i + 1, sum) + f(i + 1, sum ^ nums[i]);
        };

        return f(0, 0);
    }

    int bitmask1(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int s = 0; s < (1 << n); ++s) {
            int sum = 0;
            for (int state = s, i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    sum ^= nums[i];
                }
            }
            ret += sum;
        }

        return ret;
    }

    int bitmask2(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>()) << (nums.size() - 1);
    }

    int subsetXORSum(vector<int>& nums) {
        //return dfs(nums);
        //return bitmask1(nums);
        return bitmask2(nums);
    }
};
