class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        return Complex(a) * Complex(b);
    }

private:
    class Complex {
    public:
        Complex(int r, int i)
            : real(r)
            , imag(i) {
        }

        Complex(const string& s) {
            size_t index = s.find_first_of("+");
            real = stoi(s.substr(0, index));
            string imagStr = s.substr(index + 1, s.size() - index - 2);
            if (imagStr.empty()) {
                imag = 1;
            }
            else {
                imag = stoi(imagStr);
            }
        }

        operator string() const {
            ostringstream oss;

            oss << real;
            oss << "+";
            oss << imag;
            oss << "i";

            return oss.str();
        }

        Complex operator*(const Complex& complex) {
            int realTmp = real * complex.real - imag * complex.imag;
            int imagTmp = real * complex.imag + imag * complex.real;
            return Complex(realTmp, imagTmp);
        }

        int real;
        int imag;
    };
};