class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int> ret(n, 1);

        unordered_map<int, int> fillDays; // <lake, fillDay>
        set<int> dryDays;
        for (int d = 0; d < n; ++d) {
            int lake = rains[d];
            if (lake == 0) {
                dryDays.insert(d);
            }
            else {
                ret[d] = -1;
                if (fillDays.find(lake) != fillDays.end()) {
                    auto itr = dryDays.lower_bound(fillDays[lake]);
                    if (itr == dryDays.end()) {
                        return {};
                    }
                    ret[*itr] = lake;
                    dryDays.erase(itr);
                }
                fillDays[lake] = d;
            }
        }

        return ret;
    }
};
