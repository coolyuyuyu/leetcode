class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ret = 0;
        for (const string& log : logs) {
            if (log == "../") {
                ret = std::max(ret - 1, 0);
            }
            else if (log == "./") {
            }
            else {
                ++ret;
            }
        }

        return ret;
    }
};
