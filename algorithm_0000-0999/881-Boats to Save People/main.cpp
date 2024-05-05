class Solution {
public:
    // Time: O(nlogn)
    int greedy1(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int ret = 0;
        for (int lft = 0, rht = people.size() - 1; lft <= rht; --rht) {
            if (people[lft] + people[rht] <= limit) {
                ++lft;
            }
            ++ret;
        }

        return ret;
    }

    // Time: O(n + limit)
    int greedy2(vector<int>& people, int limit) {
        int cnts[limit + 1];
        for (int i = 0; i <= limit; ++i) {
            cnts[i] = 0;
        }
        for (int w : people) {
            ++cnts[w];
        }

        int ret = 0;
        for (int lft = 0, rht = limit; 0 <= rht; --rht) {
            while (cnts[rht] > 0) {
                --cnts[rht];
                ++ret;

                while (lft < rht && cnts[lft] == 0) {
                    ++lft;
                }
                if (cnts[lft] > 0 && lft + rht <= limit) {
                    --cnts[lft];
                }
            }
        }

        return ret;
    }

    int numRescueBoats(vector<int>& people, int limit) {
        //return greedy1(people, limit);
        return greedy2(people, limit);
    }
};
