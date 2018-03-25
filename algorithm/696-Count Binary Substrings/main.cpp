class Solution {
public:
    int countBinarySubstrings_V0(const string& s) {
        assert(s.empty() == false);

        vector<int> groups;
        groups.emplace_back(1);
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                groups.back() += 1;
            }
            else {
                groups.emplace_back(1);
            }
        }

        int count = 0;
        for (size_t i = 1; i < groups.size(); ++i) {
            count += min(groups[i - 1], groups[i]);
        }

        return count;
    }

    int countBinarySubstrings_V1(const string& s) {
        assert(s.empty() == false);

        int answer = 0;
        int cur = 1;
        int pre = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cur;
            }
            else {
                answer += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        answer += min(cur, pre);

        return answer;
    }

    int countBinarySubstrings(string s) {
        return countBinarySubstrings_V1(s);
    }
};