class Solution {
public:
    // sliding window
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int ret = 0;

        vector<int> freq(n, 0);
        for (int lft = 0, rht = 0, numDiffTypes = 0; lft < n; ++lft) {
            while (rht < n && (numDiffTypes < 2 || numDiffTypes ==2 && 0 < freq[fruits[rht]])) {
                if (freq[fruits[rht]]++ == 0) {
                    ++numDiffTypes;
                }
                ++rht;
            }

            ret = std::max(ret, rht - lft);

            if (--freq[fruits[lft]] == 0) {
                --numDiffTypes;
            }
        }

        return ret;
    }
};
