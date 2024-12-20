class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        std::function<int(int)> splitToSorted = [&](int s) {
            int nums[n];
            std::copy(arr.begin(), arr.end(), nums);

            int numChunks = 0;
            for (int lft = 0, rht = 0; rht < n; lft = rht) {
                while (rht < n && (s >> lft & 1) == (s >> rht & 1)) {
                    ++rht;
                }
                ++numChunks;

                std::sort(nums + lft, nums + rht);
                for (int i = lft; i < rht; ++i) {
                    if (nums[i] != i) {
                        return 0;
                    }
                }
            }

            return numChunks;
        };

        int ret = 0;
        for (int s = 0; s < (1 << (n - 1)); ++s) {
            ret = std::max(ret, splitToSorted(s));
        }

        return ret;
    }
};
