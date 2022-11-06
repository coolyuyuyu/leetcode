class Solution {
public:
    long long totalCost(vector<int> costs, int k, int candidates) {
        auto comp = [](pair<int, int> lft, pair<int, int> rht) {
            if (lft.first == rht.first) {
                return lft.second > rht.second;
            }
            else {
                return lft.first > rht.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);


        int lft = 0, rht = costs.size() - 1;
        for (int i = 0; i < candidates && lft <= rht; ++lft, ++i) {
            pq.emplace(costs[lft], lft);
        }
        for (int i = 0; i < candidates && lft <= rht; --rht, ++i) {
            pq.emplace(costs[rht], rht);
        }

        long long c = 0;
        for (int i = 0; i < k; ++i) {
            pair<int, int> p = pq.top();
            pq.pop();

            c += p.first;

            if (lft <= rht) {
                if (p.second < lft) {
                    pq.emplace(costs[lft], lft);
                    ++lft;
                }
                else {
                    pq.emplace(costs[rht], rht);
                    --rht;
                }
            }
        }


        return c;
    }
};