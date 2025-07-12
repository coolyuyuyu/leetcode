class Solution {
public:
    // Time: O(NlogN), Space: O(N)
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        multiset<int> frees;
        frees.insert(startTime.front());
        for (int i = 1; i < n; ++i) {
            frees.insert(startTime[i] - endTime[i - 1]);
        }
        frees.insert(eventTime - endTime.back());

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int lft = startTime[i] - (i > 0 ? endTime[i - 1] : 0);
            int rht = (i + 1 < n ? startTime[i + 1] : eventTime) - endTime[i];
            int t = endTime[i] - startTime[i];

            frees.erase(frees.find(lft));
            frees.erase(frees.find(rht));
            if (frees.lower_bound(t) != frees.end()) {
                ret = std::max(ret, lft + t + rht);
            }
            else {
                ret = std::max(ret, lft  + rht);
            }
            frees.insert(lft);
            frees.insert(rht);
        }

        return ret;
    }
};
