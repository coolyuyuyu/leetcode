class Solution {
public:
    int nthSuperUglyNumber_Heap(int n, vector<int>& primes) {
        assert(0 < n);

        priority_queue<long, vector<long>, greater<long>> pq; // min_heap
        pq.push(1);
        while (0 < --n) {
            long num = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == num) {
                pq.pop();
            }

            for (int prime : primes) {
                pq.push(num * prime);
            }
        }

        return pq.top();
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        return nthSuperUglyNumber_Heap(n, primes);
    }
};