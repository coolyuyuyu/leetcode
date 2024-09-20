class Solution {
public:
    unordered_map<char, std::function<int(int, int)>> op2func {
        {'+', std::plus<int>()},
        {'-', std::minus<int>()},
        {'*', std::multiplies<int>()},
    };

    vector<int> topdnDFS(const vector<int>& nums, const vector<std::function<int(int, int)>>& funcs) {
        int n = nums.size();

        // all possible results from computing all the different possible ways to group nums[i:j]
        vector<int> dp[n][n];
        std::function<vector<int>(int, int)> f = [&](int i, int j) {
            vector<int>& ret = dp[i][j];
            if (!ret.empty()) { return ret; }

            if (i == j) {
                ret.push_back(nums[i]);
            }
            else {
                for (int k = i; k < j; ++k) {
                    for (int opd1 : f(i, k)) {
                        for (int opd2 : f(k + 1, j)) {
                            ret.push_back(funcs[k](opd1, opd2));
                        }
                    }
                }
            }

            return ret;
        };

        return f(0, n - 1);
    }

    vector<int> btmupDP(const vector<int>& nums, const vector<std::function<int(int, int)>>& funcs) {
        int n = nums.size();

        // all possible results from computing all the different possible ways to group nums[i:j]
        vector<int> dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i].push_back(nums[i]);
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                for (int k = i; k < j; ++k) {
                    for (int opd1 : dp[i][k]) {
                        for (int opd2 : dp[k + 1][j]) {
                            dp[i][j].push_back(funcs[k](opd1, opd2));
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<std::function<int(int, int)>> funcs;
        for (int i = 0; i < expression.size(); ++i) {
            int num = 0;
            for (; i < expression.size() && std::isdigit(expression[i]); ++i) {
                num = num * 10 + (expression[i] - '0');
            }
            nums.push_back(num);

            if (i < expression.size()) {
                funcs.push_back(op2func[expression[i]]);
            }
        }

        //return topdnDFS(nums, funcs);
        return btmupDP(nums, funcs);
    }
};
