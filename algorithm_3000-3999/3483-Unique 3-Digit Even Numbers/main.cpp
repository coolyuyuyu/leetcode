class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        unordered_set<int> nums;
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) { continue; }
            for (int j = 0; j < n; ++j) {
                if (j == i) { continue; }
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) { continue; }
                    if (digits[k] & 1) { continue; }
                    nums.insert(100 * digits[i] + 10 * digits[j] + 1 * digits[k]);
                }
            }
        }

        return nums.size();
    }
};
