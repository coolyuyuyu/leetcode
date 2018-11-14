class Solution {
public:
    int gcd(int x, int y) {
        while (x > 0) {
            int tmp = y % x;
            y = x;
            x = tmp;
        }

        return y;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> sizes;
        for (const int num : deck) {
            sizes[num]++;
        }

        unordered_map<int, int>::iterator itr = sizes.begin();
        if (itr == sizes.end()) {
            return false;
        }

        int divisor = itr->second;
        if (divisor < 2) {
            return false;
        }

        while (itr != sizes.end()) {
            divisor = gcd(divisor, itr->second);
            if (divisor < 2) {
                return false;
            }

            ++itr;
        }

        return true;
    }
};