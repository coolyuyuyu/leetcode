class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lft = 0, rht = citations.size();
        while (lft < rht) {
            int mid = lft + (rht - lft) / 2;
            if (citations[mid] >= n - mid) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return n - rht;
    }
};