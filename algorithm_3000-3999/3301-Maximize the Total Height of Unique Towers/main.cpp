class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        priority_queue<int> pq;
        for (int h : maximumHeight) {
            pq.push(h);
        }

        long long ret = 0;
        for (int preH = INT_MAX; !pq.empty(); pq.pop()) {
            int h = pq.top();
            if (h >= preH) {
                h = preH - 1;
            }
            if (h <= 0) {
                return -1;
            }

            ret += h;

            preH = h;
        }

        return ret;
    }
};
