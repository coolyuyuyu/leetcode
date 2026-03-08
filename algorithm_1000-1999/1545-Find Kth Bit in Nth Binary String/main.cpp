class Solution {
public:
    char iterative(int n, int k) {
        --k;

        int len = 1;
        for (int i = 1; i < n; ++i) {
            len = len * 2 + 1;
        }

        int flip = 0;
        for (int i = n; i > 1; --i, len = (len - 1) / 2) {
            int mid = len / 2;
            if (k == mid) { return (flip & 1) ? '0' : '1';; }
            else if (k > mid) {
                k = mid - (k - mid);
                ++flip;
            }
        }

        return (flip & 1) ? '1' : '0';
    }

    char recursive(int n, int k) {
        int len = 1;
        for (int i = 1; i < n; ++i) {
            len = len * 2 + 1;
        }

        std::function<char(int, int)> dfs = [&](int k, int len) -> char {
            if (len == 1) { return '0'; }
            else if (k == (len + 1) / 2) { return '1'; }
            else if (k < (len + 1) / 2) {
                return dfs(k, (len - 1) / 2);
            }
            else {
                return '0' + ('1' - dfs(len - k + 1, (len - 1) / 2));
            }
        };

        return dfs(k, len);
    }

    char findKthBit(int n, int k) {
        //return iterative(n, k);
        return recursive(n, k);
    }
};
