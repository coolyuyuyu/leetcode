class Solution {
public:
    // O(n)
    int linear(const vector<int>& arr, int k) {
        for (int val : arr) {
            if (val <= k) {
                ++k;
            }
            else {
                return k;
            }
        }

        return k;
    }

    // O(logn)
    int bsearch(const vector<int>& arr, int k) {
        // lft, ...., mid, ..., rht
        // S: [1, 2, ..., mid-1]
        // T: [all arr elements which is less then mid]
        // if mid == kth missing element
        //     => len(S) - len(T) = k - 1

        int lft = 1, rht = arr.back() + k;
        while (lft < rht) {
            int mid = rht - (rht - lft) / 2;
            int s = mid - 1;
            int t = std::distance(arr.begin(), std::lower_bound(arr.begin(), arr.end(), mid));
            if ((s - t) <= (k - 1)) {
                lft = mid;
            }
            else {
                rht = mid - 1;
            }
        }

        return lft;
    }

    int findKthPositive(vector<int>& arr, int k) {
        //return linear(arr, k);
        return bsearch(arr, k);
    }
};
