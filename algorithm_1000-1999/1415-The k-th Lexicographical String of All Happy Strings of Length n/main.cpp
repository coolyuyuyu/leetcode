class Solution {
public:
    string recursive(int n, int k) {
        string s;
        std::function<void(int, int)> f = [&](int n, int k) {
            if (n == 0) { return; }

            int t = k / pow(2, n - 1);
            if (!s.empty() && t > 1) {
                s.clear();
                return;
            }
            else if (t > 2) {
                s.clear();
                return;
            }

            char c = 'a' + t;
            if (!s.empty() && s.back() <= c) {
                ++c;
            }
            s.push_back(c);

            f(n - 1, k - t * pow(2, n - 1));
        };
        f(n, k - 1);

        return s;
    }

    string iterative(int n, int k) {
        --k;

        string ret;
        for (int i = n; i >= 1; --i) {
            int t = k / pow(2, i - 1);
            if (i == n) {
                if (t >= 3) {
                    return "";
                }
            }
            else {
                if (t >= 2) {
                    return "";
                }
            }

            char c = 'a' + t;
            if (!ret.empty() && ret.back() <= c) {
                ++c;
            }
            ret.push_back(c);

            k -= t * pow(2, i - 1);
        }

        return ret;
    }

    string getHappyString(int n, int k) {
        //return recursive(n, k);
        return iterative(n, k);
    }
};
