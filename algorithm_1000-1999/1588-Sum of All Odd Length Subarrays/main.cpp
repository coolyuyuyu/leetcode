class Solution {
public:
    int bruteforce(const vector<int>& arr) {
        int n = arr.size();

        int ret = 0;
        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; (i + len - 1) < n; ++i) {
                ret += std::accumulate(arr.begin() + i, arr.begin() + i + len, 0);
            }
        }

        return ret;
    }

    int math(const vector<int>& arr) {
        // arr A[0, 1, 2, ..., i, i+1, ..., n-1], len = n
        // The number of non-empty suffix from arr[0:i]: i+1
        // The number of prefix (including empty) from arr[i+1:n-1]: n-i
        // The number of subarray containing a[i] k: (i+1) * (n-i)
        // The number of odd-length subarray containing : (k+1) / 2

        int sum = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            sum += ((i + 1) * (n - i) + 1) / 2 * arr[i];
        }
        return sum;
    }

    int sumOddLengthSubarrays(vector<int>& arr) {
        //return bruteforce(arr);
        return math(arr);
    }
};
