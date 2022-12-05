class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int teamCnt = skill.size() / 2;
        map<int, int> cnts;
        int sum = 0;
        for (int num : skill) {
            sum += num;
            ++cnts[num];
        }
        if ((sum % teamCnt) != 0) {
            return -1;
        }

        long long ret = 0;
        for (int teamSkill = sum / teamCnt; !cnts.empty();) {
            int skill1 = cnts.begin()->first;
            if (--cnts.begin()->second == 0) {
                cnts.erase(cnts.begin());
            }

            int skill2 = teamSkill - skill1;
            if (cnts[skill2] == 0) {
                return -1;
            }
            if (--cnts[skill2] == 0) {
                cnts.erase(skill2);
            }

            ret += (skill1 * skill2);
        }

        return ret;
    }
};
