class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ret = 0;
        for (const auto& operation : operations) {
            ret += (operation[1] == '+' ? 1 : -1);
        }

        return ret;
    }
};
