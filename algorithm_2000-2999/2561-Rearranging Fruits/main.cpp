class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnts;
        int m = INT_MAX;
        for (int i = 0; i < basket1.size(); ++i) {
            ++cnts[basket1[i]];
            --cnts[basket2[i]];
            m = std::min({m, basket1[i], basket2[i]});
        }

        priority_queue<int, vector<int>, greater<>> pq;
        for (const auto& [num, cnt] : cnts) {
            if ((cnt % 2) != 0) {
                return -1;
            }
            for (int i = 0; i < abs(cnt); i += 2) {
                pq.push(num);
            }
        }

        long long ret = 0;
        for (size_t i = pq.size() / 2; 0 < i--;) {
            int val = pq.top();
            pq.pop();

            ret += std::min((2 * m), val);
        }

        return ret;
    }
};
