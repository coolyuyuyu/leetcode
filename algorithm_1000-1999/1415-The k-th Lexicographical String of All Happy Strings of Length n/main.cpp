class Solution {
public:
    void recursion(int n, int k, string& s) {
        if (n == 0) {
            return;
        }

        int t = k / pow(2, n - 1);
        if (s.empty()) {
            if (2 < t) {
                s.clear();
                return;
            }
        }
        else if (1 < t){
            s.clear();
            return;
        }

        char c = 'a' + t;
        if (!s.empty() && s.back() <= c) {
            ++c;
        }
        s.push_back(c);

        recursion(n - 1, k - t * pow(2, n - 1), s);
    }

    string getHappyString(int n, int k) {
        string s;
        recursion(n, k - 1, s);
        return s;
    }
};
