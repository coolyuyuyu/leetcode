class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ret = 0;
        for (const string& detail : details) {
            int age = (detail[11] - '0') * 10 + (detail[12] - '0');
            if (age > 60) {
                ++ret;
            }
        }

        return ret;
    }
};
