class Solution {
public:
    bool isHappy(int n) {
        set<int> visited;
        while (n != 1) {
            pair<set<int>::const_iterator, bool> p = visited.insert(n);
            if (p.second == false) {
                return false;
            }

            int tmp = 0;
            while (n != 0) {
                int digit = n % 10;
                tmp += (digit * digit);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};