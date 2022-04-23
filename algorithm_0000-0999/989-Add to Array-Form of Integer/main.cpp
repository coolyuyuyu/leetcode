class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for (size_t i = num.size(); 0 < i-- && 0 < k;) {
            num[i] += k % 10;
            k /= 10;
            if (10 <= num[i]) {
                num[i] %= 10;
                ++k;
            }
        }
        if (0 < k) {
            size_t n = floor(log10(k)) + 1;
            num.insert(num.begin(), n, 0);
            while (0 < n--) {
                num[n] = k % 10;
                k /= 10;
            }
        }


        return num;
    }
};
