class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int minVal = *min_element(A.begin(), A.end());

        int sum = 0;
        while (0 < minVal) {
            sum += (minVal % 10);
            minVal /= 10;
        }

        return (sum % 2 == 0 ? 1 : 0);
    }
};
