class Solution {
public:
    long long minimumSteps(string s) {
        long long ret = 0;
        for (int idx0 = 0, idx1 = 0; idx0 < s.size(); ++idx0) {
            if (s[idx0] == '1') {
                continue;
            }
            else if (idx0 == idx1){
                ++idx1;
                continue;
            }

            while (s[idx1] == '0') {
                ++idx1;
            }
            std::swap(s[idx0], s[idx1]);

            ret += idx0 - idx1;
        }

        return ret;
    }
};
