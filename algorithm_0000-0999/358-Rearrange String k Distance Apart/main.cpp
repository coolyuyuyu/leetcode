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
        while (!pq.empty()) {
            if (pq.size() < k && 1 < pq.top().first) {
                return "";
            }

            vector<pair<int, char>> tmp;
            int n = std::min<int>(k, pq.size());
            for (int i = 0; i < n; ++i) {
                auto [cnt, c] = pq.top();
                pq.pop();

                ret.push_back(c);
                if (1 < cnt) {
                    tmp.emplace_back(cnt - 1, c);
                }
            }

            for (const auto& [cnt, c] : tmp) {
                pq.emplace(cnt, c);
            }
        }

        return ret;
    }
};
