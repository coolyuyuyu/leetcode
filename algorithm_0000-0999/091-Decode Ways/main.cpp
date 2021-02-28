class Solution {
public:
    int numDecodingsRecv(const string& s, size_t index) {
        size_t len = s.size();
        if (index == len) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }
        else {
            int num = numDecodingsRecv(s, index + 1);
            if (index + 1 < len) {
                if (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')) {
                    num += numDecodingsRecv(s, index + 2);
                }
            }
            return num;
        }
    }

    int numDecodingsRecv(const string& s) {
        if (s.empty()) {
            return 0;
        }

        return numDecodingsRecv(s, 0);
    }

    int numDecodingsMemoRecv(const string& s, size_t index, vector<int>& nums) {
        if (nums[index] != -1) {
            return nums[index];
        }

        size_t len = s.size();
        if (s[index] == '0') {
            return nums[index] = 0;
        }
        else {
            int num = numDecodingsMemoRecv(s, index + 1, nums);
            if (index + 1 < len) {
                if (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')) {
                    num += numDecodingsMemoRecv(s, index + 2, nums);
                }
            }
            return nums[index] = num;
        }
    }

    int numDecodingsMemoRecv(const string& s) {
        if (s.empty()) {
            return 0;
        }

        vector<int> nums(s.size() + 1, -1);
        nums.back() = 1;
        return numDecodingsMemoRecv(s, 0, nums);
    }

    int numDecodingsMemoIter(const string& s) {
        if (s.empty()) {
            return 0;
        }

        size_t len = s.size();
        vector<int> nums(len + 1, -1);
        nums.back() = 1;
        for (size_t i = s.size(); i > 0; --i) {
            size_t index = i - 1;

            if (s[index] == '0') {
                nums[index] = 0;
            }
            else {
                int num = numDecodingsMemoRecv(s, index + 1, nums);
                if (index + 1 < len) {
                    if (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')) {
                        num += numDecodingsMemoRecv(s, index + 2, nums);
                    }
                }
                nums[index] = num;
            }
        }

        return nums[0];
    }

    int numDecodingsIter(const string& s) {
        if (s.empty()) {
            return 0;
        }

        size_t len = s.size();
        size_t num1 = 1;
        size_t num2 = 0;
        for (size_t i = s.size(); i > 0; --i) {
            size_t index = i - 1;

            if (s[index] == '0') {
                num2 = num1;
                num1 = 0;
            }
            else {
                int tmp = num1;
                if (index + 1 < len) {
                    if (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')) {
                        tmp += num2;
                    }
                }
                num2 = num1;
                num1 = tmp;
            }
        }

        return num1;
    }

    int numDecodings(string s) {
        return numDecodingsIter(s);
    }
};