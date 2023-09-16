class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        priority_queue<int> pq;
        for (const auto& [_, cnt] : cnts) {
            pq.push(cnt);
        }

        while (2 <= pq.size()) {
            int cnt1 = pq.top();
            pq.pop();
            int cnt2 = pq.top();
            pq.pop();

            if (cnt1 > 1) {
                pq.push(cnt1 - 1);
            }
            if (cnt2 > 1) {
                pq.push(cnt2 - 1);
            }
        }

        int ret = 0;
        while (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }

        return ret;
    }
};
