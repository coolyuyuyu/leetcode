class Solution {
public:
    string byPQ(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> pq;
        for (const auto& [c, cnt] : cnts) {
            pq.emplace(cnt, c);
        }

        if (pq.top().first > (s.size() + 1) / 2) {
            return "";
        }

        string ret;
        while (pq.size() >= 2) {
            auto [cnt1, c1] = pq.top(); pq.pop();
            auto [cnt2, c2] = pq.top(); pq.pop();
            ret.push_back(c1);
            ret.push_back(c2);
            if (cnt1 - 1 > 0) { pq.emplace(cnt1 - 1, c1); }
            if (cnt2 - 1 > 0) { pq.emplace(cnt2 - 1, c2); }
        }
        if (!pq.empty()) {
            assert(pq.top().first == 1);
            ret.push_back(pq.top().second);
        }

        return ret;
    }

    string byGreedy(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> pq;
        for (const auto& [c, cnt] : cnts) {
            pq.emplace(cnt, c);
        }

        if (pq.top().first > (s.size() + 1) / 2) {
            return "";
        }

        string ret(s.size(), '\0');
        for (int i = 0; !pq.empty();) {
            auto [cnt, c] = pq.top(); pq.pop();
            for (; 0 < cnt--; ) {
                ret[i] = c;
                i += 2;
                if (i >= ret.size()) {
                    i = 1;
                }
            }
        }

        return ret;
    }

    string reorganizeString(string s) {
        //return byPQ(s);
        return byGreedy(s);
    }
};
