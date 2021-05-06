class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> counts(37, 0);
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            for (int num = i; 0 < num; num /= 10) {
                sum += (num % 10);
            }
            ++counts[sum];
        }

        int maxVal = *max_element(counts.begin(), counts.end());
        return count(counts.begin(), counts.end(), maxVal);
    }
};
