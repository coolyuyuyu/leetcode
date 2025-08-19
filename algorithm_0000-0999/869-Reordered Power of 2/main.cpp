class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string y = std::to_string(n);
        std::sort(y.begin(), y.end());

        for (int i = 0; i < 31; ++i) {
            string x = std::to_string(1 << i);
            std::sort(x.begin(), x.end());
            if (x == y) {
                return true;
            }
        }

        return false;
    }
};
