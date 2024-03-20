class Solution {
public:
    // TLE
    long long byPQ(vector<int>& milestones) {
        priority_queue<int> pq;
        for (int milestone : milestones) {
            pq.push(milestone);
        }

        long long ret = 0;
        while (pq.size() >= 2) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            ret += 2;

            if (x - 1 > 0) {
                pq.push(x - 1);
            }
            if (y - 1 > 0) {
                pq.push(y - 1);
            }
        }
        if (!pq.empty()) {
            ret += 1;
        }

        return ret;
    }

    long long byGreedy(vector<int>& milestones) {
        long long sum = accumulate(milestones.begin(), milestones.end(), 0LL);
        int max = *std::max_element(milestones.begin(), milestones.end());
        if (max <= (sum + 1) / 2) {
            return sum;
        }
        else {
            return (sum - max) * 2 + 1;
        }
    }

    long long numberOfWeeks(vector<int>& milestones) {
        //return byPQ(milestones);
        return byGreedy(milestones);
    }
};
