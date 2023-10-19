class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = (1 << req_skills.size());
        unordered_map<string, int> skill2id;
        for (const string& skill : req_skills) {
            skill2id.emplace(skill, skill2id.size());
        }

        int n = people.size();
        int skillset[n];
        for (int i = 0; i < n; ++i) {
            skillset[i] = 0;
            for (const string& skill : people[i]) {
                skillset[i] |= (1 << skill2id[skill]);
            }
        }

        // state: binary representation of all skills
        // dp1[state]: the minimum number of people to cover the requires skillset
        // dp2[state]: the minimum people combination to cover the requires skillset
        int dp1[m];
        long dp2[m];
        for (int state = 0; state < m; ++state) {
            dp1[state] = INT_MAX;
            dp2[state] = 0;
        }
        dp1[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int state = 0; state < m; ++state) {
                if (dp1[state] == INT_MAX) { continue; }

                int nxtState = state | skillset[i];
                if (dp1[state] + 1 < dp1[nxtState]) {
                    dp1[nxtState] = dp1[state] + 1;
                    dp2[nxtState] = dp2[state] | (1L << i);
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (dp2[m - 1] & (1L << i)) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
