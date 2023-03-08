class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string out;
        for (auto& str : strs) {
            encode(str, out);
        }

        return out;
    }

    void encode(size_t val, string& out) {
        do {
            unsigned char v = static_cast<unsigned char>(val) & MASK;
            if (MASK < val) {
                v |= CARRY;
            }
            out += v;
        } while (val >>= SHIFT);
    }

    void encode(const string& str, string& out) {
        encode(str.size(), out);
        out += str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        for (string::const_iterator itr = s.begin(); itr != s.end();) {
            ret.emplace_back();
            decode(itr, ret.back());
        }

        return ret;
    }

    void decode(string::const_iterator& itr, size_t& val) {
        val = 0;

        int shiftCnt = 0;
        size_t c;
        do {
            c = *itr++;
            val |= (c & MASK) << shiftCnt;
            shiftCnt += SHIFT;
        } while (c & CARRY);
    }

    void decode(string::const_iterator& itr, string& str) {
        size_t len;
        decode(itr, len);

        str.resize(len, '\0');

        std::copy(itr, itr + len, str.begin());
        itr += len;
    }

private:
    static constexpr unsigned char MASK =  0b01111111;
    static constexpr unsigned char CARRY = 0b10000000;
    static constexpr int SHIFT = 7;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
