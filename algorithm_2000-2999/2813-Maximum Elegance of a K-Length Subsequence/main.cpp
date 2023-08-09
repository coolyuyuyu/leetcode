class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();

        std::sort(items.rbegin(), items.rend(), [&](const auto& item1, const auto& item2) { return item1[0] < item2[0]; });

        long long sum = 0;
        unordered_map<int, int> cateCnts;
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
        for (int i = 0; i < k; ++i) {
            sum += items[i][0];
            ++cateCnts[items[i][1]];
            pq.emplace(items[i][0], items[i][1]);
        }

        long long ret = sum + cateCnts.size() * cateCnts.size();
        for (int i = k; i < n; ++i) {
            if (cateCnts.find(items[i][1]) != cateCnts.end()) { continue; }
            while (!pq.empty()) {
                auto [profit, cate] = pq.top();
                pq.pop();

                if (cateCnts[cate] > 1) {
                    sum -= profit;
                    --cateCnts[cate];
                    sum += items[i][0];
                    ++cateCnts[items[i][1]];

                    ret = std::max<long long>(ret, sum + cateCnts.size() * cateCnts.size());

                    pq.emplace(items[i][0], items[i][1]);

                    break;
                }
            }
        }

        return ret;
    }
};
