class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int teamCnt = skill.size() / 2;

        long long sum = 0;
        unordered_map<int, int> cnts;
        for (int s : skill) {
            sum += s;
            ++cnts[s];
        }
        if (sum % teamCnt != 0) { return -1; }
        int teamSum = sum / teamCnt;

        long long ret = 0;
        for (auto itr1 = cnts.begin(); itr1 != cnts.end(); ++itr1) {
            const auto& [s1, cnt1] = *itr1;
            if (s1 > teamSum / 2) { continue; }
            int s2 = teamSum - s1;
            auto itr2 = cnts.find(s2);
            if (itr2 == cnts.end() || itr2->second != cnt1) {
                return -1;
            }

            if (s1 * 2 ==  teamSum) {
                ret += 1LL* s1 * s2 * cnt1 / 2;
            }
            else {
                ret += 1LL* s1 * s2 * cnt1;
            }
        }

        return ret;
    }
};
