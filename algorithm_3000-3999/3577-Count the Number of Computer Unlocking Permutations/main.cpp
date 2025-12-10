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

        if (std::find_if(complexity.begin() + 1, complexity.end(), [&](int num){ return num <= complexity[0]; }) != complexity.end()) {
            return 0;
        }

        return factorial(complexity.size() - 1);
    }
};
