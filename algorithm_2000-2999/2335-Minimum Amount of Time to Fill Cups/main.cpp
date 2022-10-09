class Solution {
public:
    int fillCups(vector<int>& amounts) {
        int secs = 0;

        priority_queue<int> pq;
        for (int amount : amounts) {
            if (0 < amount) {
                pq.push(amount);
            }
        }
        while (2 < pq.size()) {
            int a1 = pq.top();
            pq.pop();
            int a2 = pq.top();
            pq.pop();

            if (1 < a1) {
                pq.push(a1 - 1);
            }
            if (1 < a2) {
                pq.push(a2 - 1);
            }

            ++secs;
        }
        if (!pq.empty()) {
            secs += pq.top();
        }

        return secs;
    }
};
