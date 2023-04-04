class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = pair<int, int>{reward1[i], reward2[i]};
        }

        std::sort(
            arr.begin(), arr.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2){
                return (p1.first - p1.second) > (p2.first - p2.second);
            });

        int ret = 0;
        for (int i = 0; i < k; ++i) {
            ret += arr[i].first;
        }
        for (int i = k; i < n; ++i) {
            ret += arr[i].second;
        }

        return ret;
    }
};
