class Solution {
public:
    // Time: O(nlogn + T), T = 2000
    int f1(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& t1, const vector<int>& t2) { return t1[1] < t2[1]; });

        vector<bool> busy(2001, false);
        for (const auto& task : tasks) {
            int overlap = std::count(busy.begin() + task[0], busy.begin() + task[1] + 1, true);
            int left = task[2] - overlap;
            for (int i = task[1]; task[0] <= i && 0 < left; --i) {
                if (busy[i] == false) {
                    busy[i] = true;
                    --left;
                }
            }
        }

        return std::count(busy.begin() + 1, busy.end(), true);
    }

    // Time: O(nlogn + logn)
    int f2(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& t1, const vector<int>& t2) { return t1[1] < t2[1]; });

        vector<array<int, 3>> busy; // <start, end, presum>
        busy.push_back({-1, -1, 0});
        for (const auto& task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            auto itr = std::lower_bound(
                busy.begin(), busy.end(),
                array<int, 3>{start, 0, 0},
                [](const array<int, 3>& t1, const array<int, 3>& t2) { return t1[0] < t2[0]; });
            itr = std::prev(itr);

            int overlap = busy.back()[2] - (*itr)[2];
            if (start <= (*itr)[1]) {
                overlap += ((*itr)[1] - start + 1);
            }

            int left = duration - overlap;
            int cur = end;
            while (0 < left) {
                int avail = cur - busy.back()[1];
                if (avail < left) {
                    left -= (cur - busy.back()[1]);
                    cur = busy.back()[0] - 1;
                    busy.pop_back();
                }
                else {
                    if (avail == left) {
                        cur = busy.back()[0] - 1;
                        busy.pop_back();
                        left = 0;
                    }
                    busy.push_back({cur - left + 1, end, busy.back()[2] + end - (cur - left + 1) + 1});
                    left = 0;
                }
            }
        }

        return busy.back()[2];
    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        //return f1(tasks);
        return f2(tasks);
    }
};
