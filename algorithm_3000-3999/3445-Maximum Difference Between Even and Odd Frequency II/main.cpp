class Solution {
public:
    int computeState(int cntA, int cntB) {
        return ((cntA & 1) << 1) | (cntB & 1);
    }

    int maxDifference(string s, int k, char a, char b) {
        int n = s.size();
        s.insert(s.begin(), '#');

        unordered_map<int, int> m;
        int cntsA[n + 1]; cntsA[0] = 0;
        int cntsB[n + 1]; cntsB[0] = 0;

        // s: X X X X X X X X
        //        i         j
        // s[i:j]
        // max(cntA[j] - cntA[i - 1]) - (cntB[j] - cntB[i - 1])
        // => max(cntA[j] - cntB[j]) - (cntA[i - 1] - cntB[i - 1])

        int ret = INT_MIN;
        for (int lft = 1, rht = 1; rht <= n; ++rht) {
            cntsA[rht] = cntsA[rht - 1] + (s[rht] == a ? 1 : 0);
            cntsB[rht] = cntsB[rht - 1] + (s[rht] == b ? 1 : 0);;

            for (; rht - lft + 1 >= k && (cntsB[rht] - cntsB[lft - 1] >= 2); ++lft) {
                int preCntA = cntsA[lft - 1];
                int preCntB = cntsB[lft - 1];
                int preState = computeState(preCntA, preCntB);
                if (m.find(preState) == m.end()) {
                    m[preState] = preCntA - preCntB;
                }
                else {
                    m[preState] = std::min(m[preState], preCntA - preCntB);
                }
            }

            int state = computeState(cntsA[rht], cntsB[rht]);
            int target = state ^ 0b10;
            if (m.find(target) != m.end()) {
                ret = std::max(ret, (cntsA[rht] - cntsB[rht]) - (m[target]));
            }
        }

        return ret;
    }

    int maxDifference(string s, int k) {
        int ret = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) { continue; }
                ret = std::max(ret, maxDifference(s, k, a, b));
            }
        }

        return ret;
    }
};
