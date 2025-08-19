class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.push_back(card);
        }

        std::function<unordered_set<double>(int, int)> f = [&](int i, int j) {
            if (i == j) {
                return unordered_set<double>({nums[i]});
            }

            unordered_set<double> ret;
            for (int k = i; k < j; ++k) {
                for (double a : f(i, k)) {
                    for (double b : f(k + 1, j)) {
                        ret.insert(a + b);
                        ret.insert(a - b);
                        ret.insert(a * b);
                        if (b != 0.0) {
                            ret.insert(a / b);
                        }
                    }
                }
            }

            return ret;
        };

        std::sort(nums.begin(), nums.end());
        do {
            for (double result : f(0, nums.size() - 1)) {
                if (std::abs(result - 24) < 1e-10) {
                    return true;
                }
            }
        } while (std::next_permutation(nums.begin(), nums.end()));

        return false;
    }
};
