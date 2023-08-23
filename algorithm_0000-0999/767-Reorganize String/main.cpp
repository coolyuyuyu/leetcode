class Solution {
public:
    string greedy(const string& s) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        vector<pair<int, char>> pairs;
        for (const auto& [c, cnt] : cnts) {
            pairs.emplace_back(cnt, c);
        }
        std::sort(pairs.rbegin(), pairs.rend());

        if (((s.size() + 1) / 2) < pairs[0].first ) {
            return "";
        }

        string ret(s.size(), ' ');
        int idx = 0;
        for (const auto& [cnt, c] : pairs) {
            for (int i = 0; i < cnt; ++i) {
                ret[idx] = c;
                idx += 2;

                if (ret.size() <= idx) {
                    idx = 1;
                }
            }
        }

        return ret;
    }

    string pqueue(const string& s) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> pq;
        for (const auto& [c, cnt] : cnts) {
            pq.emplace(cnt, c);
        }

        if (((s.size() + 1) / 2) < pq.top().first ) {
            return "";
        }

        string ret;
        while (!pq.empty()) {
            vector<pair<int, char>> tmp;
            for (int i = 0, n = std::min<int>(2, pq.size()); i < n; ++i) {
                auto [cnt, c] = pq.top();
                pq.pop();
                ret += c;
                --cnt;

                if (0 < cnt) {
                    tmp.emplace_back(cnt, c);
                }
            }

            for (const auto& [cnt, c] : tmp) {
                pq.emplace(cnt, c);
            }
        }

        return ret;
    }

    string reorganizeString(string s) {
        //return greedy(s);
        return pqueue(s);
    }
};
