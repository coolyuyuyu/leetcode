class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret = encode(strs.size());
        for (auto& str : strs) {
            ret += encode(str);
        }

        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        istringstream iss(s);

        size_t len;
        decode(iss, len);

        vector<string> ret(len);
        for (string& str : ret) {
            decode(iss, str);
        }

        return ret;
    }

    string encode(size_t val) {
        string s;

        unsigned char MASK = 0b01111111;
        unsigned char CARRY = 0b10000000;
        int shift = 7;
        do {
            unsigned char v = static_cast<unsigned char>(val) & MASK;
            if (MASK < val) {
                v |= CARRY;
            }
            s += v;
        } while (val >> shift);


        return s;
    }

    string encode(const string& s) {
        return encode(s.size()) + s;

    }

    void decode(istringstream& iss, size_t& val) {
        unsigned char MASK = 0b01111111;
        unsigned char CARRY = 0b10000000;
        int shift = 7;

        val = 0;


        int shiftCnt = 0;
        unsigned char c;
        do {

            iss >> c;
            val |= size_t(c & MASK) << shiftCnt;
            shiftCnt += shift;

        } while (c & CARRY);
    }


    void decode(istringstream& iss, string& str) {
        size_t len; decode(iss, len);
        str.resize(len);
        for (size_t i = 0; i < len; ++i) {
            iss >> str[i];
        }

    }
};


/*
271. Encode and Decode Strings
*/