class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return capital[idx1] < capital[idx2]; });

        priority_queue<int> maxPQ;
        for (int i = 0; 0 < k--;) {
            for (; i < n && capital[indexes[i]] <= w; ++i) {
                maxPQ.push(profits[indexes[i]]);
            }
            if (maxPQ.empty()) { break; }

            w += maxPQ.top();
            maxPQ.pop();
        }

        return w;
    }
};
