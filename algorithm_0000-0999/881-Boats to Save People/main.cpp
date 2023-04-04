class Solution {
public:
    // Time: O(nlogn)
    int greedy(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int ret = 0;
        for (int lft = 0, rht = people.size() - 1; lft <= rht;) {
            if ((people[lft] + people[rht]) <= limit) {
                ++lft;
            }
            --rht;
            ++ret;
        }

        return ret;
    }

    // Time: O(n + limit)
    int counting(const vector<int>& people, int limit) {
        vector<int> cnts(limit + 1, 0);
        for (int w : people) {
            ++cnts[w];
        }

        int ret = 0;
        for (int lft = 1, rht = limit; 0 < rht; --rht) {
            while (0 < cnts[rht]) {
                --cnts[rht];
                ++ret;

                while (lft < rht && cnts[lft] == 0) {
                    ++lft;
                }
                if (0 < cnts[lft] && (lft + rht) <= limit) {
                    --cnts[lft];
                }
            }
        }

        return ret;
    }

    int numRescueBoats(vector<int>& people, int limit) {
        //return greedy(people, limit);
        return counting(people, limit);
    }
};
