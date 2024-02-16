class Solution {
public:
    unordered_map<char, std::function<int(int, int)>> char2func = {
        {'+', std::plus<int>()},
        {'*', std::multiplies<int>()},
    };

    // 241. Different Ways to Add Parentheses
    unordered_set<int> computeAllResults(vector<int> nums, vector<char> ops) {
        int n = nums.size();

        // dp[i][j]: all posibile results from computing all the different possible ways to group nums[i:j]
        unordered_set<int> dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = {nums[i]};
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                for (int k = i; k < j; ++k) {
                    for (int opd1 : dp[i][k]) {
                        for (int opd2 : dp[k + 1][j]) {
                            int ans = char2func[ops[k]](opd1, opd2);
                            if (ans > 1000) { continue; }
                            dp[i][j].insert(ans);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }

    // 227. Basic Calculator II
    int computeCorrectResults(vector<int> nums, vector<char>& ops) {
        int n = nums.size();

        vector<int> remainings;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == '*') {
                nums[i + 1] *= nums[i];
                nums[i] = 0;
            }
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }

    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < s.size(); ++i) {
            int num = 0;
            for (; i < s.size() && isdigit(s[i]); ++i) {
                num = num * 10 + s[i] - '0';
            }
            nums.push_back(num);
            if (i < s.size()) {
                ops.push_back(s[i]);
            }
        }

        unordered_set<int> allResults = computeAllResults(nums, ops);
        int correctResult = computeCorrectResults(nums, ops);

        int ret = 0;
        for (int answer : answers) {
            if (answer == correctResult) {
                ret += 5;
            }
            else if (allResults.find(answer) != allResults.end()) {
                ret += 2;
            }
        }

        return ret;
    }
};
