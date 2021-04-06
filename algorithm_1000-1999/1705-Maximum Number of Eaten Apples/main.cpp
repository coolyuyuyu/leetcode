class Solution {
public:
    int eatenApples_Heap(vector<int>& apples, vector<int>& days) {
        int numEaten = 0;

        typedef pair<int, int> CountTime;
        auto comp = [](const CountTime& ct1, const CountTime& ct2) {
            return (ct1.second > ct2.second);
        };
        priority_queue<CountTime, vector<CountTime>, decltype(comp)> pq(comp); // min_heap
        for (int t = 0; (t < apples.size() || !pq.empty()); ++t) {
            if (t < apples.size() && 0 < apples[t]) {
                pq.emplace(apples[t], t + days[t]);
            }

            while (!pq.empty() && pq.top().second <= t) {
                pq.pop();
            }
            if (!pq.empty()) {
                ++numEaten;

                CountTime ct = pq.top();
                pq.pop();

                if (0 < --ct.first) {
                    pq.push(ct);
                }
            }
        }

        return numEaten;
    }

    int eatenApples(vector<int>& apples, vector<int>& days) {
        return eatenApples_Heap(apples, days);
    }
};
