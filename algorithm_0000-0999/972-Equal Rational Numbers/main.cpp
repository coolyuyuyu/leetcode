class Solution {
public:
    bool isRationalEqual(string s, string t) {
        std::function<tuple<bool, double, string>(string)> f = [](string s) {
            size_t ppos = s.find('(');
            if (ppos == string::npos) {
                return make_tuple(true, std::stod(s), string(""));
            }

            // x.y(z) => a(b)
            string a = s.substr(0, ppos);
            string b = s.substr(ppos + 1, s.size() - a.size() - 2);
            bool rpAll0 = std::all_of(b.begin(), b.end(), [](char c){ return c == '0'; });
            if (rpAll0) {
                return make_tuple(true, std::stod(a), string(""));
            }

            bool rpAll9 = std::all_of(b.begin(), b.end(), [](char c){ return c == '9'; });
            if (rpAll9) {
                int dpos = a.find('.');
                int nrpSize = a.size() - dpos - 1;
                return make_tuple(true, std::stod(a) + 1 * std::pow(10, -nrpSize), string(""));
            }

            while (a.size() < 20) {
                a += b;
            }
            a = a.substr(0, 20);
            return make_tuple(false, 0.0, a);
        };

        auto [isValS, valS, strS] = f(s);
        auto [isValT, valT, strT] = f(t);
        if (isValS != isValT) {
            return false;
        }
        else if (isValS) {
            return std::abs(valS - valT) < 1e-10;
        }
        else {
            return strS == strT;
        }
    }
};
