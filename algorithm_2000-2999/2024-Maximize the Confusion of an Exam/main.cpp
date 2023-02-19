class Solution {
public:
    int maxConsecutiveTargets(const string& s, char t, int k) {
        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(); lft < n; ++lft) {
            for (; rht < n && (s[rht] == t || 0 < k); ++rht) {
                if (s[rht] != t) {
                    --k;
                }
            }
            ret = std::max(ret, rht - lft); // [lft, rht);

            if (s[lft] != t) {
                ++k;
            }
        }

        return ret;
    }

    // two pointers
    // Time: O(n)
    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(maxConsecutiveTargets(answerKey, 'T', k), maxConsecutiveTargets(answerKey, 'F', k));
    }
};
