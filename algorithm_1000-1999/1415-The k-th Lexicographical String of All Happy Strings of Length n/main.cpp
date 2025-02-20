class Solution {
public:
    string getHappyString(int n, int k) {
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
};
