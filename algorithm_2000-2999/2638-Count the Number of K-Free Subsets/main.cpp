class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        vector<vector<int>> groups(k);
        for (int num : nums) {
            groups[num % k].push_back(num);
        }

        long long ret = 1;
        for (auto& arr : groups) {
            std::sort(arr.begin(), arr.end());

            long long takeN = 1, takeY = 0;
            for (int i = 0; i < arr.size(); ++i) {
                long long tmpN = takeN, tmpY = takeY;
                if (0 < i && (arr[i - 1] + k == arr[i])) {
                    takeN = tmpN + tmpY;
                    takeY = tmpN;
                }
                else {
                    takeN = takeY = tmpN + tmpY;
                }
            }

            ret *= (takeN + takeY);
        }

        return ret;
    }
};
