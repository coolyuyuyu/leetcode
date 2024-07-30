class Solution {
public:
    // Time: O(n^3)
    int bruteforce(vector<int>& rating) {
        int n = rating.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (rating[i] < rating[j] && rating[j] < rating[k]) {
                        ++ret;
                    }
                    if (rating[i] > rating[j] && rating[j] > rating[k]) {
                        ++ret;
                    }
                }
            }
        }

        return ret;
    }

    // Time: O(n^2)
    int math(vector<int>& rating) {
        int n = rating.size();

        int ret = 0;
        for (int j = 0; j < n; ++j) {
            int lftLT = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++lftLT;
                }
            }
            int lftGT = j - lftLT;

            int rhtLT = 0;
            for (int k = j + 1; k < n; ++k) {
                if (rating[j] > rating[k]) {
                    ++rhtLT;
                }
            }
            int rhtGT = n - j - 1 - rhtLT;

            ret += lftLT * rhtGT;
            ret += lftGT * rhtLT;
        }
        
        return ret;
    }

    int numTeams(vector<int>& rating) {
        //return bruteforce(rating);
        return math(rating);
    }
};
