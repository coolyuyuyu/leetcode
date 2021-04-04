class Solution {
public:
    int nthUglyNumber_Heap(int n) {
        assert(0 < n);

        priority_queue<long, vector<long>, greater<long>> pq; // min_heap
        pq.push(1);
        while (0 < --n) {
            long num = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == num) {
                pq.pop();
            }

            pq.push(num * 2);
            pq.push(num * 3);
            pq.push(num * 5);
        }

        return pq.top();
    }

    int nthUglyNumber(int n) {
        return nthUglyNumber_Heap(n);
    }
};