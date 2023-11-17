class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();

        deque<int> dq;

        int ret = 0;
        long long sum = 0;
        for (int lft = 0, rht = 0; rht < n; ++lft) {
            for (; rht < n && (std::max(chargeTimes[rht], (dq.empty() ? 0 : chargeTimes[dq.front()])) +  (rht - lft + 1) * (sum + runningCosts[rht])) <= budget; ++rht) {
                while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[rht]) {
                    dq.pop_back();
                }
                dq.push_back(rht);
                sum += runningCosts[rht];
            }

            ret = std::max(ret, rht - lft);

            if (lft < rht) {
                if(!dq.empty() && dq.front() == lft) {
                    dq.pop_front();
                }
                sum -= runningCosts[lft];
            }
            else {
                ++rht;
            }
        }

        return ret;
    }
};
