class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.push_back(card);
        }

        std::function<unordered_set<double>(int, int)> f = [&](int i, int j) {
            if (i == j) {
                return unordered_set<double>{nums[i]};
            }

            unordered_set<double> ret;
            for (int k = i; k < j; ++k) {
                for (double opd1 : f(i, k)) {
                    for (double opd2 : f(k + 1, j)) {
                        ret.insert(opd1 + opd2);
                        ret.insert(opd1 - opd2);
                        ret.insert(opd1 * opd2);
                        if (opd2 != 0) {
                            ret.insert(opd1 / opd2);
                        }
                    }
                }
            }

            return ret;
        };

        std::sort(nums.begin(), nums.end());
        do {
            unordered_set<double> results = f(0, 3);
            for (double result : results) {
                if (std::abs(result - 24) <= 1e-10) {
                    return true;
                }
            }
        } while (next_permutation(nums.begin(), nums.end()));

        return false;
    }
};
