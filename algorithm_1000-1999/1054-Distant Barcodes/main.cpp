class Solution {
public:
    vector<int> byPQ(vector<int>& barcodes) {
        unordered_map<int, int> cnts;
        for (int code : barcodes) {
            ++cnts[code];
        }

        priority_queue<pair<int, int>> pq;
        for (const auto& [code, cnt] : cnts) {
            pq.emplace(cnt, code);
        }

        assert(pq.top().first <= (barcodes.size() + 1) / 2);

        vector<int> ret;
        while (pq.size() >= 2) {
            auto [cnt1, code1] = pq.top(); pq.pop();
            auto [cnt2, code2] = pq.top(); pq.pop();
            ret.push_back(code1);
            ret.push_back(code2);
            if (cnt1 - 1 > 0) { pq.emplace(cnt1 - 1, code1); }
            if (cnt2 - 1 > 0) { pq.emplace(cnt2 - 1, code2); }
        }
        if (!pq.empty()) {
            assert(pq.top().first == 1);
            ret.push_back(pq.top().second);
        }

        return ret;
    }

    vector<int> byGreedy(vector<int>& barcodes) {
        unordered_map<int, int> cnts;
        for (int code : barcodes) {
            ++cnts[code];
        }

        priority_queue<pair<int, int>> pq;
        for (const auto& [code, cnt] : cnts) {
            pq.emplace(cnt, code);
        }

        assert(pq.top().first <= (barcodes.size() + 1) / 2);

        vector<int> ret(barcodes.size());
        for (int i = 0; !pq.empty();) {
            auto [cnt, code] = pq.top(); pq.pop();
            for (; 0 < cnt--; ) {
                ret[i] = code;
                i += 2;
                if (i >= ret.size()) {
                    i = 1;
                }
            }
        }

        return ret;
    }

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        //return byPQ(barcodes);
        return byGreedy(barcodes);
    }
};
