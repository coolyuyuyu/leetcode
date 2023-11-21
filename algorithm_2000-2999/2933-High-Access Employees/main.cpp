class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();

        std::sort(access_times.begin(), access_times.end(), [](auto& ac1, auto& ac2){ return ac1[1] < ac2[1]; });

        std::function<int(const string&)> countMins = [](const string& t) {
            int hh = (t[0] - '0') * 10 + (t[1] - '0');
            int mm = (t[2] - '0') * 10 + (t[3] - '0');
            return hh * 60 + mm;
        };

        unordered_set<string> ret;

        unordered_map<string, int> cnts;
        for (int lft = 0, rht = 0; rht < n; ++lft) {
            int lftMins = countMins(access_times[lft][1]);
            while (rht < n && countMins(access_times[rht][1]) - lftMins <= 59) {
                if (++cnts[access_times[rht][0]] >= 3) {
                    ret.insert(access_times[rht][0]);
                }
                ++rht;
            }

            --cnts[access_times[lft][0]];
        }

        return vector<string>(ret.begin(), ret.end());
    }
};
