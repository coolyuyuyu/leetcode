class Solution {
public:
    int byPQ(vector<int>& nums) {
        priority_queue<int> pq;
        for (int num : nums) {
            if (num > 0) {
                pq.emplace(num);
            }
        }

        int ret = 0;
        while (pq.size() >= 2) {
            vector<int> tmps;
            for (int i = 0; i < 2; ++i) {
                auto num = pq.top(); pq.pop();
                tmps.emplace_back(num);
            }

            ret += 1;

            for (int num : tmps) {
                if (num - 1 > 0) {
                    pq.emplace(num - 1);
                }
            }
        }
        if (!pq.empty()) {
            assert(pq.size() == 1);
            int num = pq.top(); pq.pop();
            ret += num;
        }

        return ret;
    }

    int byGreedy(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max = *std::max_element(nums.begin(), nums.end());
        if (max <= (sum + 1) / 2) {
            return (sum + 1) / 2;
        }
        else {
            return max;
        }
    }

    int fillCups(vector<int>& amount) {
        //return byPQ(amount);
        return byGreedy(amount);
    }
};
