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
        unordered_map<int, int> cnts;
        for (int num : deck) {
            ++cnts[num];
        }

        int g = cnts.begin()->second;
        for (const auto p : cnts) {
            g = gcd(g, p.second);
            if (g < 2) {
                break;
            }
        }

        return g != 1;
    }
};
