class Solution {
public:
    void findStrobogrammaticHelper(size_t index, size_t last, string& num, vector<string>& nums) {
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
                findStrobogrammaticHelper(index + 1, last, num, nums);
            }
        }
    }


    vector<string> findStrobogrammatic(int n) {
        if (n == 0) {
            return {};
        }

        string num(n, '#');
        vector<string> nums;
        findStrobogrammaticHelper(0, (n % 2 ? n / 2 + 1 : n / 2), num, nums);
        return nums;
    }
};