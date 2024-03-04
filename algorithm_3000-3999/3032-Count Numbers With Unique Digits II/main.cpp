class Solution {
public:
    int numberCount(int a, int b) {
        int ret = 0;
        for (int num = a; num <= b; ++num) {
            unordered_set<int> digits;
            bool unique = true;
            for (int x = num; x; x /= 10) {
                if (digits.insert(x % 10).second == false) {
                    unique = false;
                    break;
                }
            }
            if (unique) {
                ++ret;
            }
        }

        return ret;
    }
};
