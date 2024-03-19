class Solution {
public:
    string byPQ(int a, int b) {
        priority_queue<pair<int, char>> pq;
        pq.emplace(a, 'a');
        pq.emplace(b, 'b');

        string ret(a + b, '\0');
        int idx = 0;
        while (!pq.empty()) {
            if (pq.size() == 1) {
                auto [cnt, c] = pq.top(); pq.top();
                assert(cnt < 3);
                for (int i = 0; i < cnt; ++i) {
                    ret[idx++] = c;
                }
                break;
            }

            auto [cnt1, c1] = pq.top(); pq.pop();
            auto [cnt2, c2] = pq.top(); pq.pop();

            int k = (cnt1 == cnt2 ? 1 : 2);
            for (int i = 0; i < k; ++i) {
                ret[idx++] = c1;
            }
            ret[idx++] = c2;

            if (cnt1 - k > 0) { pq.emplace(cnt1 - k, c1); }
            if (cnt2 - 1 > 0) { pq.emplace(cnt2 - 1, c2); }
        }

        return ret;
    }

    string byGreedy(int a, int b) {
        int cnt1 = a, cnt2 = b;
        char c1 = 'a', c2 = 'b';
        if (cnt2 > cnt1) {
            std::swap(cnt1, cnt2);
            std::swap(c1, c2);
        }

        string ret(cnt1 + cnt2, '\0');
        int idx = 0;
        int diff = cnt1 - cnt2;
        for (int i = 0; i < cnt2; ++i) {
            ret[idx++] = c1;
            if (diff > 0) {
                ret[idx++] = c1;
                --diff;
            }

            ret[idx++] = c2;
        }
        assert(diff < 3);
        for (int i = 0; i < diff; ++i) {
            ret[idx++] = c1;
        }

        return ret;
    }

    string strWithout3a3b(int a, int b) {
        //return byPQ(a, b);
        return byGreedy(a, b);
    }
};
