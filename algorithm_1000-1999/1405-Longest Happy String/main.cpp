class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) { pq.emplace(a, 'a'); }
        if (b) { pq.emplace(b, 'b'); }
        if (c) { pq.emplace(c, 'c'); }

        string ret;
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            if (pq.empty()) {
                for (int n = std::min(cnt1, 2); 0 < n--;) {
                    ret += ch1;
                }
                break;
            }
            auto [cnt2, ch2] = pq.top(); pq.pop();

            for (int n = std::min(1 + cnt1 - cnt2, 2); 0 < n--;) {
                ret += ch1;
                --cnt1;
            }
            ret += ch2;
            --cnt2;

            if (cnt1) { pq.emplace(cnt1, ch1); }
            if (cnt2) { pq.emplace(cnt2, ch2); }
        }

        return ret;
    }
};
