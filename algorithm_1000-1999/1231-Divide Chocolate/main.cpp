class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        std::function<bool(int)> checkSplittable = [&](int lowerBound) {
            int sum = 0, numParts = 0;
            for (int sweet : sweetness) {
                sum += sweet;
                if (sum >= lowerBound) {
                    if (++numParts >= k + 1) {
                        return true;
                    }
                    sum = 0;
                }
            }

            return false;
        };

        int lo = *std::min_element(sweetness.begin(), sweetness.end()), hi = std::accumulate(sweetness.begin(), sweetness.end(), 0) / (k + 1);
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkSplittable(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
