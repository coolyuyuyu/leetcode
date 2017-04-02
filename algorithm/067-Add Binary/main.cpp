class Solution {
public:
    string addBinary(string a, string b) {
        string c(max(a.size(), b.size()), '0');
        string::reverse_iterator iterA = a.rbegin(), iterB = b.rbegin(), iterC = c.rbegin();

        bool carry = false;
        while (iterC != c.rend()) {
            int num = 0;

            if (iterA != a.rend()) {
                num += (*iterA - '0');
                ++iterA;
                
            }
            if (iterB != b.rend()) {
                num += (*iterB - '0');
                ++iterB;
            }

            if (carry) {
                ++num;
            }

            if (2 <= num) {
                *iterC = (num % 2 + '0');
                carry = true;
            }
            else {
                *iterC = num + '0';
                carry = false;
            }
            ++iterC;
        }

        if (carry) {
            c.insert(c.begin(), '1');
        }

        return c;
    }
};