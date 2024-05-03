class Solution {
public:
    int maxPotholes(string road, int budget) {
        priority_queue<int> maxPQ;
        for (int i = 0, n = road.size(); i < n; ++i) {
            if (road[i] == '.') { continue; }
            int j = i;
            while (j < n && road[j] == 'x') {
                ++j;
            }
            maxPQ.push(j - i);

            i = j;
        }

        int ret = 0;
        while (!maxPQ.empty() && budget > 0) {
            int cnt = maxPQ.top();
            maxPQ.pop();

            int diff = std::min(budget, cnt + 1);
            budget -= diff;
            ret += (diff - 1);
        }

        return ret;
    }
};
