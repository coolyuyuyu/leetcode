class Solution {
public:
    int f1(vector<int>& nums) {
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

    int f2(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        int maxCnt = 0;
        for (const auto& [_, cnt] : cnts) {
            maxCnt = std::max(maxCnt, cnt);
        }

        int n = nums.size();
        if (maxCnt > n / 2) {
            return n - (n - maxCnt) * 2;
        }
        else {
            return n & 1;
        }
    }

    int minLengthAfterRemovals(vector<int>& nums) {
        //return f1(nums);
        return f2(nums);
    }
};
