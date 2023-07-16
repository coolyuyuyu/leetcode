class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size(), n = people.size();

        unordered_map<string, int> skill2id;
        for (int i = 0; i < m; ++i) {
            skill2id[req_skills[i]] = i;
        }

        vector<int> dp(1 << m, INT_MAX / 2); // dp[state]: the minimal number of people to cover the skill state
        vector<long> member(1 << m, 0); // member[state]: the minimal people combination to cover the skill state
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int state1 = 0;
            for (const string& skill : people[i]) {
                state1 |= (1 << skill2id[skill]);
            }

            auto tmp = dp;
            for (int state2 = 0; state2 < (1 << m); ++state2) {
                int newState = state2 | state1;
                if ((tmp[state2] + 1) < dp[newState]) {
                    dp[newState] = tmp[state2] + 1;
                    member[newState] = member[state2] | (1L << i);
                }
            }
        }

        long retMember = member[(1 << m) - 1];
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if ((retMember >> i) & 1) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
