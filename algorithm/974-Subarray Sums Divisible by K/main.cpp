class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> reminderCounts(K, 0);

        int remainder = 0;
        for (int num : A) {
            remainder = ((remainder + num) % K + K) % K;
            ++reminderCounts[remainder];
        }

        int count = 0;
        for (int reminderCount : reminderCounts) {
            if (0 < reminderCount) {
                count += reminderCount * (reminderCount - 1) / 2;
            }
        }
        count += reminderCounts[0];

        return count;
    }
};