class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        // 564. Find the Closest Palindrome
        std::function<bool(const string&)> checkPalindrome = [](const string& s) {
            int n = s.size();
            for (int i = 0, j = n - 1; i < j; ++i, --j) {
                if (s[i] != s[j]) { return false; }
            }

            return true;
        };
        std::function<long long(int)> costPalindrome = [&](int t) {
            long long ret = 0;
            for (int num : nums) {
                ret += std::abs(num - t);
            }

            return ret;
        };
        std::function<string(const string&)> nextSmallerPalindrom = [](const string& s) {
            int n = s.size();
            string t = s;

            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[n - 1 - i] = t[i];
            }
            if (t < s) {
                return t;
            }

            int carry = -1;
            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[i] += carry;
                if (isdigit(t[i])) {
                    carry = 0;
                }
                else {
                    t[i] = '9';
                }
                t[n - 1 - i] = t[i];
            }

            if (t[0] == '0' && n > 1) {
                return string(n - 1, '9');
            }
            else {
                return t;
            }
        };
        std::function<string(const string&)> nextGreaterPalindrom = [](const string& s) {
            int n = s.size();
            string t = s;

            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[n - 1 - i] = t[i];
            }
            if (t > s) {
                return t;
            }

            int carry = 1;
            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[i] += carry;
                if (isdigit(t[i])) {
                    carry = 0;
                }
                else {
                    t[i] = '0';
                }
                t[n - 1 - i] = t[i];
            }

            if (carry) {
                t.assign(n + 1, '0');
                t[0] = t[n] = '1';
                return t;
            }
            else {
                return t;
            }
        };

        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int median = n & 1 ? (nums[n / 2]) : ((nums[n / 2 - 1] + nums[n / 2]) / 2);
        string medianStr = std::to_string(median);

        if (checkPalindrome(medianStr)) {
            return costPalindrome(median);
        }
        else {
            string a = nextSmallerPalindrom(medianStr);
            string b = nextGreaterPalindrom(medianStr);
            return std::min(costPalindrome(stoll(a)), costPalindrome(stoll(b)));
        }
    }
};
