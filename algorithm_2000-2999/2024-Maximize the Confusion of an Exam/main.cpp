class Solution {
public:
    // Time: O(n)
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        std::function<int(char, int)> f = [&](char target, int k) {
            int ret = 0;
            for (int lft = 0, rht = 0; lft < n; ++lft) {
                for (; rht < n && (answerKey[rht] == target || 0 < k); ++rht) {
                    if (answerKey[rht] != target) {
                        --k;
                    }
                }

                ret = std::max(ret, rht - lft);

                if (answerKey[lft] != target) {
                    ++k;
                }
            }

            return ret;
        };

        return std::max(f('T', k), f('F', k));
    }
};
