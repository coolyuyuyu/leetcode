class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) {
            return s;
        }

        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> pq;
        for (const auto& [c, cnt] : cnts) {
            pq.emplace(cnt, c);
        }

        string ret;
        while (pq.size() >= k) {
            vector<pair<int, char>> tmps;
            for (int i = 0; i < k; ++i) {
                auto [cnt, c] = pq.top(); pq.pop();
                ret.push_back(c);
                tmps.emplace_back(cnt, c);
            }

            for (const auto& [cnt, c] : tmps) {
                if (cnt - 1 > 0) {
                    pq.emplace(cnt - 1, c);
                }
            }
        }
        if (!pq.empty()) {
            if (pq.top().first > 1) {
                return "";
            }
            while (!pq.empty()) {
                auto [_, c] = pq.top(); pq.pop();
                ret.push_back(c);
            }
        }

        return ret;
    }
};
