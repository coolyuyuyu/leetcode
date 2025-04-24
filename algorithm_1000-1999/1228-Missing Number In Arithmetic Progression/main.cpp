class Solution {
public:
    // Time: O(N)
    int f1(vector<int>& arr) {
        int d = (arr.back() - arr.front()) / (int)arr.size();
        for (int i = 1, v = arr.front() + d; i < arr.size(); ++i, v += d) {
            if (v != arr[i]) {
                return v;
            }
        }

        return arr.front();
    }

    // Time: O(logN)
    int f2(vector<int>& arr) {
        int d = (arr.back() - arr.front()) / (int)arr.size();
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr.front() + mid * d != arr[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return arr.front() + d * lo;
    }

    int missingNumber(vector<int>& arr) {
        return f1(arr);
        //return f2(arr);
    }
};
