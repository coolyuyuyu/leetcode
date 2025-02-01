class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        int ret = 0;

        multiset<int> frees;
        if (startTime[0] > 0) {
            frees.insert(startTime[0]);
        }
        for (int i = 1; i < n; ++i) {
            if (startTime[i] - endTime[i - 1] > 0) {
                frees.insert(startTime[i] - endTime[i - 1]);
            }
        }
        if (eventTime - endTime[n - 1]) {
            frees.insert(eventTime - endTime[n - 1]);
        }

        for (int i = 0; i < n; ++i) {
            int lft = startTime[i] - (i > 0 ? endTime[i - 1] : 0);
            int rht = ((i + 1) < n ? startTime[i + 1] : eventTime) - endTime[i];
            if (lft) { frees.erase(frees.find(lft)); }
            if (rht) { frees.erase(frees.find(rht)); }
            if (frees.lower_bound(endTime[i] - startTime[i]) != frees.end()) {
                ret = std::max(ret, lft + (endTime[i] - startTime[i]) + rht);
            }
            else {
                ret = std::max(ret, lft + rht);
            }
            if (lft) { frees.insert(lft); }
            if (rht) { frees.insert(rht); }
        }

        return ret;
    }
};
