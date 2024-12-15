class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for (; k > 0 && !pq.empty() && pq.top() > 1; k--) {
            int gift = pq.top();
            pq.pop();
            pq.push(std::sqrt(gift));
        }

        long long ret = 0;
        for (; !pq.empty(); pq.pop()) {
            ret += pq.top();
        }

        return ret;
    }
};
