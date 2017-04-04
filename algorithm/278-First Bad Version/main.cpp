// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int bgn = 0;
        int end = n;
        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            }
            else {
                bgn = mid;
            }
        }
        return end;
    }
};