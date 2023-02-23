class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);

        auto comp = [&capital](int i1, int i2) {
            return capital[i1] < capital[i2];
        };
        std::sort(indexes.begin(), indexes.end(), comp);

        int ret = w;
        priority_queue<int> pq;
        for (int i = 0; 0 < k; k--) {
            for (; i < n && capital[indexes[i]] <= ret; ++i) {
                pq.push(profits[indexes[i]]);
            }

            if (pq.empty()) {
                break;
            }
            ret += pq.top();
            pq.pop();
        }

        return ret;

    }
};
