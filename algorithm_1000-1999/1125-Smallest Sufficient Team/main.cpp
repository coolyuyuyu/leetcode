class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skill2id;
        for (const string& skill : req_skills) {
            skill2id.emplace(skill, skill2id.size());
        }
        int m = (1 << skill2id.size());

        int n = people.size();
        vector<int> skillsets(n, 0);
        for (int i = 0; i < n; ++i) {
            int& skillset = skillsets[i];
            for (const string& skill : people[i]) {
                skillset |= (1 << skill2id[skill]);
            }
        }

        // state: binary representation of skills
        // dp1[state]: the minimum number of people to cover the state of skills
        // dp2[state]: the minimum people combination to cover the state of skills
        vector<int> dp1(m, INT_MAX);
        dp1[0] = 0;
        vector<long> dp2(m, 0);
        for (int state1 = 0; state1 < m; ++state1) {
            if (dp1[state1] == INT_MAX) { continue; }
            for (int j = 0; j < n; ++j) {
                int state2 = state1 | skillsets[j];
                if (dp1[state1] + 1 < dp1[state2]) {
                    dp1[state2] = dp1[state1] + 1;
                    dp2[state2] = dp2[state1] | (1L << j);
                }
            }
        }

        vector<int> ret;
        for (int j = 0; j < n; ++j) {
            if ((dp2[m - 1] >> j) & 1) {
                ret.push_back(j);
            }
        }

        return ret;
    }
};
