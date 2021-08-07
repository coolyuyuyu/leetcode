class Solution {
public:
    int findKthPositive_NaiveBruteForce(vector<int>& arr, int k) {
        if (k < arr.front()) {
            return k;
        }
        k -= (arr.front() - 1);

        for (size_t i = 0; (i + 1) < arr.size(); ++i) {
            int missingCnt = arr[i + 1] - arr[i] - 1;
            if (k <= missingCnt) {
                return (arr[i] + k);
            }
            k -= missingCnt;
        }

        return (arr.back() + k);
    }

    int findKthPositive_OptimizedBruteForce(vector<int>& arr, int k) {
        for (int num : arr) {
            if (k < num) {
                return k;
            }
            else {
                ++k;
            }
        }

        return k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        // Time: O(N)
        // return findKthPositive_NaiveBruteForce(arr, k);

        // Time: O(N)
        return findKthPositive_OptimizedBruteForce(arr, k);
    }
};
