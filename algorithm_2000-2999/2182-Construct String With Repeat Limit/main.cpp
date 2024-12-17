class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }
        priority_queue<pair<char, int>> pq;
        for (const auto& [c, cnt] : cnts) {
            pq.emplace(c, cnt);
        }

        string ret;
        while (!pq.empty()) {
            auto [c1, cnt1] = pq.top();
            pq.pop();
            if (cnt1 <= repeatLimit) {
                ret += string(cnt1, c1);
                continue;
            }
            else {
                int k = std::min(cnt1, repeatLimit);
                ret += string(k, c1);
                cnt1 -= k;
            }

            if (pq.empty()) {
                break;
            }
            auto [c2, cnt2] = pq.top();
            pq.pop();
            ret += string(1, c2);
            cnt2 -= 1;

            if (cnt1) {
                pq.emplace(c1, cnt1);
            }
            if (cnt2) {
                pq.emplace(c2, cnt2);
            }
        }

        return ret;
    }
};
