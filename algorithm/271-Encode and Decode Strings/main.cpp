class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        encodeLen(s, strs.size());

        for (const string& str : strs) {
            encodeLen(s, str.size());
            s += str;
        }

        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        auto itr = s.cbegin();

        vector<string> strs(decodeLen(itr));
        for (string& str : strs) {
            size_t size = decodeLen(itr);
            str.assign(itr, itr + size);
            itr += size;
        }
        return strs;
    }

private:
    void encodeLen(string& s, size_t n) {
        while (n > 127) {
            s.push_back(n & 255);
            n >>= 7;
        }
        s.push_back(n);
    }

    size_t decodeLen(string::const_iterator& itr) {
        size_t size = 0, base = 1;
        unsigned char c;
        do {
            c = *(itr++);
            size += ((c & 127) * base);
            base *= 128;
        } while (c & 128);

        return size;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));