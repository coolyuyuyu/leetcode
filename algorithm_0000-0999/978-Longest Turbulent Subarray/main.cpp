class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        std::function<int(int, int)> comp = [](int a, int b) {
            if (a < b) {
                return 1;
            }
            else if (a == b) {
                return 0;
            }
            else {
                return -1;
            }
        };

        int ret = 0;
        for (int i = 0, n = arr.size(); i < n;) {
            if ((i + 1 < n && arr[i] == arr[i + 1]) || i + 1 >= n) {
                ret = std::max(ret, 1);
                i = i + 1;
                continue;
            }

            int j = i + 2;
            for (int v = comp(arr[i], arr[i + 1]); j < n && comp(arr[j - 1], arr[j]) == (0 - v); ++j) {
                v = 0 - v;
            }
            ret = std::max(ret, j - i);

            i = j - 1;
        }

        return ret;
    }
};
