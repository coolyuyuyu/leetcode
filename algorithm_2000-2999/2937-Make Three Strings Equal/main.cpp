class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = std::min({s1.size(), s2.size(), s3.size()});

        int ret = 0;
        for (; n < s1.size(); ++ret) {
            s1.pop_back();
        }
        for (; n < s2.size(); ++ret) {
            s2.pop_back();
        }
        for (; n < s3.size(); ++ret) {
            s3.pop_back();
        }

        for (; s1 != s2 || s1 != s3; ret += 3) {
            s1.pop_back();
            s2.pop_back();
            s3.pop_back();
        }

        return s1.empty() ? -1 : ret;
    }
};
