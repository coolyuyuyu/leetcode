class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp = [](int num1, int num2) {
            int cnt1 = __builtin_popcount(num1), cnt2 = __builtin_popcount(num2);
            return cnt1 < cnt2 || (cnt1 == cnt2 && num1 < num2);
        };
        std::sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
