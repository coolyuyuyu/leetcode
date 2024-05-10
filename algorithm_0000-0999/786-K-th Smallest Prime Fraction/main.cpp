class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double lo = 0, hi = 1;
        double mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int cnt = 0;
            for (int num : arr) {
                auto itr = std::lower_bound(arr.begin() + 1, arr.end(), 1.0 * num / mid);
                cnt += std::distance(itr, arr.end());
            }

            if (cnt > k) {
                hi = mid;
            }
            else if (cnt < k) {
                lo = mid;
            }
            else {
                break;
            }
        }

        vector<int> ret;
        double ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            auto itr = std::lower_bound(arr.begin() + i + 1 , arr.end(), 1.0 *  arr[i] / mid);
            int j = std::distance(arr.begin(), itr);
            if (j < arr.size() && 1.0 * arr[i] / arr[j] > ans) {
                ans = 1.0 * arr[i] / arr[j];
                ret = {arr[i], arr[j]};
            }
        }

        return ret;
    }
};
