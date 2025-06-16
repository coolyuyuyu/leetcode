class Solution {
public:
    int M = 1e9 + 7;

    int countPermutations(vector<int>& complexity) {
        std::function<int(int)> factorial = [&](int n) {
            int ret = 1;
            for (int i = 1; i <= n; ++i) {
                ret = 1L * ret * i % M;
            }
            return ret;
        };

        if (std::min_element(complexity.begin(), complexity.end()) != complexity.begin()) {
            return 0;
        }
        if (std::count(complexity.begin(), complexity.end(), complexity[0]) >= 2) {
            return 0;
        }

        return factorial(complexity.size() - 1);
    }
};
