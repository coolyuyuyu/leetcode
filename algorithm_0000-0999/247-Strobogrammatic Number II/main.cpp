class Solution {
public:
    void findStrobogrammaticHelper1(size_t index, size_t last, string& num, vector<string>& nums) {
        static unordered_map<char, char> dict = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        static vector<char> candidatesAll = {'0', '1', '6', '8', '9'};
        static vector<char> candidatesBegin = {'1', '6', '8', '9'};
        static vector<char> candidatesMid = {'0', '1', '8'};

        if (index >= last) {
            nums.emplace_back(num);
        }
        else {
            vector<char>& candidates = (index == 0 ? (num.size() == 1 ? candidatesMid: candidatesBegin) : (num.size() % 2 && index == num.size() / 2 ? candidatesMid : candidatesAll));
            for (size_t i = 0; i < candidates.size(); ++i) {
                num[index] = candidates[i];
                num[num.size() - index - 1] = dict[candidates[i]];
                findStrobogrammaticHelper1(index + 1, last, num, nums);
            }
        }
    }

    vector<string> findStrobogrammatic1(int n) {
        if (n == 0) {
            return {};
        }

        string num(n, '#');
        vector<string> nums;
        findStrobogrammaticHelper1(0, (n % 2 ? n / 2 + 1 : n / 2), num, nums);
        return nums;
    }

    vector<string> findStrobogrammaticHelper2(int m, int n) {
        if (m == 0) {
            return {};
        }
        else if (m == 1) {
            return {"0", "1", "8"};
        }
        else {
            vector<string> results;
            vector<string> strs = (m == 2 ? vector<string>(1, "") : findStrobogrammaticHelper2(m - 2, n));
            for (size_t i = 0; i < strs.size(); ++i) {
                if (m != n) {
                    results.emplace_back("0" + strs[i] + "0");
                }

                results.emplace_back("1" + strs[i] + "1");
                results.emplace_back("6" + strs[i] + "9");
                results.emplace_back("8" + strs[i] + "8");
                results.emplace_back("9" + strs[i] + "6");
            }
            return results;
        }
    }

    vector<string> findStrobogrammatic2(int n) {
        return findStrobogrammaticHelper2(n, n);
    }

    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammatic2(n);
    }
};