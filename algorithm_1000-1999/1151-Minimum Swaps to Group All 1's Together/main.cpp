class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = 0;
        for (int num : data) {
            k += (num == 1 ? 1 : 0);
        }

        int ret = data.size();
        for (int i = 0, n = data.size(), cnt1 = 0; i < n; ++i) {
            cnt1 += (data[i] == 1 ? 1 : 0);
            if (i - k + 1 >= 0) {
                ret = std::min(ret, k - cnt1);
                cnt1 -= (data[i - k + 1] == 1 ? 1 : 0);
            }
        }

        return ret;
    }
};
