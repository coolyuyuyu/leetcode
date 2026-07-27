class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mxDR = 0;
        int sum = 0;
        for (int num : nums) {
            set<int> s;
            for (int x = num; x; x /= 10) {
                s.insert(x % 10);
            }
            int dr = *std::prev(s.end()) - *s.begin();
            if (dr > mxDR) {
                mxDR = dr;
                sum = num;
            }
            else if (dr == mxDR) {
                sum += num;
            }
        }

        return sum;
    }
};
