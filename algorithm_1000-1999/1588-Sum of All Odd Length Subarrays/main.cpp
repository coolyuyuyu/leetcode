class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        /*
        arr A[0, 1, 2, ..., i, i+1, ..., n-1], size = n

        Assume a subarr contain A[i]
        The number of lft choices: i+1
        The number of rht choices: n-i
        The number of subarry k = (i+1) * (n-i)
        The number of odd-length subarray: (k + 1) / 2
        */

        int sum = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            sum += ((i + 1) * (n - i) + 1) / 2 * arr[i];
        }
        return sum;
    }
};
