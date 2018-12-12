class Solution {
public:
    string multiply(string num1, string num2) {
        return BigNum(num1) * BigNum(num2);
    }

private:
    class BigNum {
        friend ostream& operator<<(ostream& os, const BigNum& bn) {
            if (bn.m_data.empty()) {
                os << 0;
            }
            else {
                ostringstream oss;
                for (size_t i = bn.m_data.size(); i-- > 0;) {
                    oss << (int)bn.m_data[i];
                }
                os << oss.str();
            }
            return os;
        }
    public:
        BigNum(const string& s = "") {
            for (size_t i = s.size(); i-- > 0;) {
                m_data.push_back(s[i] - '0');
            }
            while (!m_data.empty() && m_data.back() == 0) {
                m_data.pop_back();
            }
        }

        operator string() const {
            ostringstream oss;
            oss << *this;
            return oss.str();
        }

        bool operator==(const BigNum& rhs) const {
            return m_data == rhs.m_data;
        }

        bool operator!=(const BigNum& rhs) const {
            return !(*this == rhs);
        }

        BigNum& operator<<=(unsigned count) {
            if (*this != BigNum("0")) {
                size_t originalSize = m_data.size();
                m_data.resize(originalSize + count);
                for (size_t i = 0; i < originalSize; ++i) {
                    m_data[m_data.size() - i - 1] = m_data[m_data.size() - i - count - 1];
                }
                for (unsigned i = 0; i < count; ++i) {
                    m_data[i] = 0;
                }
            }

            return *this;
        }

        BigNum& operator>>=(unsigned count) {
            size_t originalSize = m_data.size();
            if (count > m_data.size()) {
                m_data.clear();
            }
            else {
                for (size_t i = 0; i < (originalSize - count); ++i) {
                    m_data[i] = m_data[count + i];
                }
                m_data.resize(originalSize - count);
            }

            return *this;
        }

        BigNum& operator+=(const BigNum& rhs) {
            size_t len = max(m_data.size(), rhs.m_data.size());
            unsigned char carry = 0;
            for (size_t i = 0; i < len; ++i) {
                if (m_data.size() == i) {
                    m_data.push_back(0);
                }

                unsigned char num = m_data[i] + (i < rhs.m_data.size() ? rhs.m_data[i] : 0) + carry;

                m_data[i] = num % 10;
                carry = num / 10;
            }

            if (0 < carry) {
                m_data.push_back(carry);
            }

            return *this;
        }

        BigNum operator+(const BigNum& rhs) const {
            BigNum sum = *this;
            return sum += rhs;
        }

        BigNum& operator*=(const BigNum& rhs) {
            BigNum product;
            BigNum multipicand = *this;
            BigNum multiplier = rhs;
            while (multiplier != BigNum("0")) {
                for (unsigned char i = 0; i < multiplier.m_data.front(); ++i) {
                    product += multipicand;
                }

                multipicand <<= 1;
                multiplier >>= 1;
            }

            m_data.swap(product.m_data);

            return *this;
        }

        BigNum operator*(const BigNum& rhs) const {
            BigNum product = *this;
            return product *= rhs;
        }

    private:
        vector<unsigned char> m_data;
    };
};