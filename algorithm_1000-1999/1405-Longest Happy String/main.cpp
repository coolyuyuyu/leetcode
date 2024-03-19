class Solution {
public:
    string byPQ(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) { pq.emplace(a, 'a'); }
        if (b > 0) { pq.emplace(b, 'b'); }
        if (c > 0) { pq.emplace(c, 'c'); }

        string ret;
        int idx = 0;
        while (!pq.empty()) {
            if (pq.size() == 1) {
                auto [cnt, c] = pq.top(); pq.top();
                for (int i = std::min(cnt, 2); 0 < i--;) {
                    ret.push_back(c);
                }
                break;
            }

            auto [cnt1, c1] = pq.top(); pq.pop();
            auto [cnt2, c2] = pq.top(); pq.pop();

            int k = (cnt1 == cnt2 ? 1 : 2);
            for (int i = 0; i < k; ++i) {
                ret.push_back(c1);
            }
            ret.push_back(c2);

            if (cnt1 - k > 0) { pq.emplace(cnt1 - k, c1); }
            if (cnt2 - 1 > 0) { pq.emplace(cnt2 - 1, c2); }
        }

        return ret;
    }

    string longestDiverseString(int a, int b, int c) {
        return byPQ(a, b, c);
    }
};
