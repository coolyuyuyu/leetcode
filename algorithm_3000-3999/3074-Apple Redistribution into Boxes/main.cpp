class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int cnt = std::accumulate(apple.begin(), apple.end(), 0);

        priority_queue<int> maxPQ;
        for (int c : capacity) {
            maxPQ.push(c);
        }

        int ret = 0;
        for (; cnt > 0 && !maxPQ.empty(); ++ret) {
            cnt -= maxPQ.top();
            maxPQ.pop();
        }

        return ret;
    }
};
