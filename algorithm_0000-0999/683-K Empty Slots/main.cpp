class Solution {
public:
    // Time: O(NlogN)
    int f1(vector<int>& bulbs, int k) {
        set<int> lights;

        for (int i = 0; i < bulbs.size(); ++i) {
            auto [itr, _] = lights.insert(bulbs[i]);

            auto preItr = std::prev(itr);
            if (itr != lights.begin() && bulbs[i] - *preItr == k + 1) {
                return i + 1;
            }

            auto nxtItr = std::next(itr);
            if (nxtItr != lights.end() && *nxtItr - bulbs[i] == k + 1) {
                return i + 1;
            }
        }

        return -1;
    }

    // Time: O(N)
    int f2(vector<int>& bulbs, int k) {
        vector<int> days(bulbs.size());
        for (int i = 0; i < bulbs.size(); ++i) {
            days[bulbs[i] - 1] = i + 1;

        }

        int ret = INT_MAX;
        for (int i = 0; i + k + 1 < bulbs.size();) {
            int lft = i, rht = i + k + 1;
            int j;
            bool ok = true;
            for (j = lft + 1; j <= rht - 1; ++j) {
                if (days[j] < days[lft] || days[j] < days[rht]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret = std::min(ret, std::max(days[lft], days[rht]));
                ++i;
            }
            else {
                i = j;
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }

    int kEmptySlots(vector<int>& bulbs, int k) {
        //return f1(bulbs, k);
        return f2(bulbs, k);
    }
};
