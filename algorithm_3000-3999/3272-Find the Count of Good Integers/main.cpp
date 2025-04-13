class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long factorials[10 + 1];
        factorials[0] = 1;
        for (int i = 1; i <= 10; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }

        long long ret = 0;

        int m = (n + 1) / 2;
        unordered_set<string> visited;
        for (int lo = std::pow(10, m - 1), hi = std::pow(10, m) - 1, num = lo; num <= hi; ++num) {
            string snum; {
                string lft = std::to_string(num);
                string rht = lft.substr(0, n / 2);
                std::reverse(rht.begin(), rht.end());
                snum = lft + rht;
            }
            string key; {
                key = snum;
                std::sort(key.begin(), key.end());
            }
            if (std::stoll(snum) % k == 0 && visited.find(key) == visited.end()) {
                visited.insert(key);

                vector<int> cnts(10, 0);
                for (char c : snum) {
                    ++cnts[c - '0'];
                }

                long long x = (n - cnts[0]) * factorials[n - 1];
                for (int cnt : cnts) {
                    x /= factorials[cnt];
                }

                ret += x;
            }
        }

        return ret;
    }
};
