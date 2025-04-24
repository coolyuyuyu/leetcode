class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnts(37, 0);
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            for (int num = i; num; num /= 10) {
                sum += num % 10;
            }
            ++cnts[sum];
        }

        int maxCnt = *std::max_element(cnts.begin(), cnts.end());
        return std::count(cnts.begin(), cnts.end(), maxCnt);
    }
};
