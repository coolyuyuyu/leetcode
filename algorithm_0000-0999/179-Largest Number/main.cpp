class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strs(n);
        for (int i = 0; i < n; ++i) {
            strs[i] = std::to_string(nums[i]);
        }

        std::sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) { return (s1 + s2) > (s2 + s1); });
        string ret;
        for (const auto& str : strs) {
            ret += str;
        }

        int i = 0;
        for (; i < ret.size(); ++i) {
            if (ret[i] != '0') {
                break;
            }
        }

        return i == ret.size() ? "0" : ret.substr(i);
    }
};
