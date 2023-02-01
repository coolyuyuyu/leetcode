class Solution {
public:
    bool divisible(const string& dividend, const string& divisor) {
        assert(divisor.empty() == false);

        if (dividend.empty()) {
            return true;
        }

        if ((dividend.size() % divisor.size()) != 0) {
            return false;
        }
        if (dividend.compare(0, divisor.size(), divisor) != 0) {
            return false;
        }

        for (size_t i = 0; i < dividend.size(); i += divisor.size()) {
            if (dividend.compare(i, divisor.size(), divisor) != 0) {
                return false;
            }
        }
        return true;
    }

    // try all possible prefix
    // Time: O(min(len(s1), len(s2) * (len(s1) + len(s2))
    string bruteforce(const string& s1, const string& s2) {
        for (size_t i = std::min(s1.size(), s2.size()) + 1; 1 < i--;) {
            if (0 < (s1.size() % i) || 0 < (s2.size() % i)) {
                continue;
            }
            string gcd = s1.substr(0, i);
            if (divisible(s1, gcd) && divisible(s2, gcd)) {
                return gcd;
            }
        }

        return "";
    }

    // Time: O(n ^ 2), where n = max(len(s1), len(s2))
    string gcd(const string& s1, const string& s2) {
        if (s1.size() < s2.size()) {
            return gcd(s2, s1);
        }
        else if (s2.empty()) {
            return s1;
        }
        else if (s1.compare(0, s2.size(), s2) != 0) {
            return "";
        }
        else {
            return gcd(s2, s1.substr(s2.size()));
        }
    }

    // Time: O(len(s1) + len(s2))
    string best(const string& s1, const string& s2) {
        if ((s1 + s2) != (s2 + s1)) {
            return "";
        }
        else {
            return s1.substr(0, std::gcd(s1.size(), s2.size()));
        }
    }

    string gcdOfStrings(string str1, string str2) {
        //return bruteforce(str1, str2);
        //return gcd(str1, str2);
        return best(str1, str2);
    }
};
