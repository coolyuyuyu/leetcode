class Solution {
public:
    bool containsPattern_BruteForce(vector<int>& arr, int m, int k) {
        auto check = [&arr, m, k](int i) {
            for (int a = 1; a < k; ++a) {
                for (int b = 0; b < m; ++b) {
                    if (arr[i + b] != arr[i + a * m + b]) {
                        return false;
                    }
                }
            }

            return true;
        };

        for (int i = 0; (i + m * k) < (arr.size() + 1); ++i) {
            if (check(i)) {
                return true;

            }
        }

        return false;
    }

    bool containsPattern_Optimize(vector<int>& arr, int m, int k) {
        int cnt = 0;
        for (int i = 0; (i + m) < arr.size(); ++i) {
            if (arr[i] != arr[i + m]) {
                cnt = 0;
            }
            else {
                ++cnt;
                if (cnt == ((k - 1) * m)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsPattern(vector<int>& arr, int m, int k) {
        //return containsPattern_BruteForce(arr, m, k);

        return containsPattern_Optimize(arr, m, k);
    }
};
