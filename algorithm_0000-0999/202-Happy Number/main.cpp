class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (n != 1) {
            int tmp = 0;
            for (; n; n /= 10) {
                int d = n % 10;
                tmp += (d * d);
            }
            n = tmp;

            if (s.insert(n).second == false) {
                return false;
            }
        }

        return true;
    }
};
